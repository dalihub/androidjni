import glob
import fnmatch
import os
import sys
import re


parsed = {}

toJavaTypes = { 'void' : 'void',
                'int' : 'int',
                'long' : 'long',
                'float' : 'float',
                'double' : 'double',
                'bool' : 'boolean',
                'uint8_t' : 'byte',
                'uint16_t' : 'short',
                'uint32_t' : 'int',
                'uint64_t' : 'long',
                'int8_t' : 'byte',
                'int16_t' : 'short',
                'int32_t' : 'int',
                'int64_t' : 'long',
                'string' : 'String',
                'Property::Index' : 'int', }

def cppToJavaType(typeStr):
  typeStr = str(typeStr)
  typeStr = typeStr.replace('std::', '')
  typeStr = typeStr.replace('Dali::', '')
  if typeStr in toJavaTypes:
    typeStr = toJavaTypes[typeStr]
  else:
    typeStr = typeStr.replace('::', '.')
  return typeStr            

def parseArgsList(argsList, parsed):
  print('Parsing [' + argsList + "]")
  argPattern = re.compile('(const\s+)?(?P<argType>[A-Za-z0-9_:]+)(?P<refType>(\s*(\*|\&))*\s+((\*|\&)\s*)*)(?P<argName>[A-Za-z0-9_:]+),?')
  m = argPattern.search(argsList, 0)
  while m:
    parsed.append(( m.group('argType'), m.group('refType').replace(' ',''), m.group('argName') ))
    m = argPattern.search(argsList, m.end())
  return parsed

def parseFunctionsList(classBody, parsed):
  functionPattern = re.compile('\n  (static\s+)?(const\s+)?(?P<returnType>[A-Za-z0-9_:]+)\s+(?P<functionName>[A-Za-z0-9_:]+)\(\s*(?P<argsList>.*)\s*\)(\s+const)?;')
  m = functionPattern.search(classBody, 0)
  while m:
    functionName = m.group('functionName')
    print('Found [' + functionName + "]")
    parsed[functionName] = []
    parsed[functionName].append(( m.group('returnType'), '', '' ))
    argsList = m.group('argsList')
    if argsList:
      parseArgsList(argsList, parsed[functionName])
    m = functionPattern.search(classBody, m.end())

def generateJavaFunction(functionName, parsedArgsList):
  stringBuffer = ''
  returnArg = parsedArgsList[0]
  typeStr = cppToJavaType(returnArg[0])
  stringBuffer += '    ' + 'public ' + typeStr + ' ' + functionName[0].lower() + functionName[1:]
  stringBuffer += '('
  for i in range(1, len(parsedArgsList)):
    arg = parsedArgsList[i]
    if arg[2] != '':
      stringBuffer += cppToJavaType(arg[0]) + ' ' + arg[2]
    if i != len(parsedArgsList)-1:
      stringBuffer += ', '
  stringBuffer += ')'
  stringBuffer += ' {\n'
  if typeStr != 'void':
    stringBuffer += '        return '
  else:
    stringBuffer += '        '
  stringBuffer += 'native' + functionName + '(nativeHandle'
  for i in range(1, len(parsedArgsList)):
    arg = parsedArgsList[i]
    if arg[2] != '':
      stringBuffer += ', ' + arg[2]
  stringBuffer += ');\n'
  stringBuffer += '    }\n\n'
  return stringBuffer

def generateJavaFunctionList(parsedFunctions):
  stringBuffer = ''
  for functionName in parsedFunctions:
    if functionName == 'New' or functionName == 'DownCast':
      continue
    stringBuffer += generateJavaFunction(functionName, parsedFunctions[functionName])
  return stringBuffer

def generateNativeJavaFunction(functionName, parsedArgsList):
  stringBuffer = ''
  returnArg = parsedArgsList[0]
  typeStr = cppToJavaType(returnArg[0])
  stringBuffer += '    ' + 'protected native ' + typeStr + ' native' + functionName
  stringBuffer += '(long nativeHandle'
  for i in range(1, len(parsedArgsList)):
    arg = parsedArgsList[i]
    if arg[2] != '':
      stringBuffer += ', ' + cppToJavaType(arg[0]) + ' ' + arg[2]
  stringBuffer += ');\n'
  return stringBuffer

def generateNativeJavaFunctionList(parsedFunctions):
  stringBuffer = ''
  for functionName in parsedFunctions:
    if functionName == 'New' or functionName == 'DownCast':
      continue
    stringBuffer += generateNativeJavaFunction(functionName, parsedFunctions[functionName])
  return stringBuffer

toJNITypes = { 'void' : 'void',
               'int' : 'jint',
               'long' : 'jlong',
               'float' : 'jfloat',
               'double' : 'jdouble',
               'bool' : 'jboolean',
               'uint8_t' : 'jbyte',
               'uint16_t' : 'jshort',
               'uint32_t' : 'jint',
               'uint64_t' : 'jlong',
               'int8_t' : 'jbyte',
               'int16_t' : 'jshort',
               'int32_t' : 'jint',
               'int64_t' : 'jlong',
               'string' : 'jstring',
               'Property::Index' : 'jint', }

def cppToJNIType(typeStr):
  typeStr = str(typeStr)
  typeStr = typeStr.replace('Dali::', '')
  typeStr = typeStr.replace('std::', '')
  if typeStr in toJNITypes:
    typeStr = toJNITypes[typeStr]
  else:
    typeStr = 'jobject'
  return typeStr  

def generateNativeFunction(className, functionName, parsedArgsList):
  stringBuffer = ''
  returnArg = parsedArgsList[0]
  typeStr = cppToJNIType(returnArg[0])
  stringBuffer += 'extern "C" JNIEXPORT ' + typeStr + ' JNICALL Java_com_sec_dali_object_' + className + '_native' + functionName
  stringBuffer += '(JNIEnv* jenv, jobject obj, jlong handle'
  for i in range(1, len(parsedArgsList)):
    arg = parsedArgsList[i]
    if arg[2] != '':
      stringBuffer += ', ' + cppToJNIType(arg[0]) + ' ' + arg[2]
  stringBuffer += ');\n'
  return stringBuffer

def generateNativeFunctionList(className, parsedFunctions):
  stringBuffer = ''
  for functionName in parsedFunctions:
    if functionName == 'New' or functionName == 'DownCast':
      continue
    stringBuffer += generateNativeFunction(className, functionName, parsedFunctions[functionName])
  return stringBuffer

def generateJNI(headerFilePath, generatedFilePath):
  file = open(headerFilePath, 'r')
  buffer = file.read()
  file.close()
  className = ''
  classBody = ''

  m = re.search('(class|struct)\s+DALI_[A-Za-z0-9_]+_API\s+(?P<className>[A-Za-z0-9_]+)(\s+:(\s+(public|protected|private)\s+[A-Za-z0-9_]+,?))?\s+{(?P<classBody>(.|\n)*)};', buffer) 
  if m:
    className = m.group('className')
    classBody = m.group('classBody')
    parsed[className] = {}
    parseFunctionsList(classBody, parsed[className])

  javaFileBuffer = ''
  jniBuffer = ''

  for className in parsed:
    javaClassName = className + '.java'
    javaClassBuffer = 'public class ' + className + ' {\n'
    javaClassBuffer += '    ' + 'public ' + className + '( long nativeHandle ) {\n        this.nativeHandle = nativeHandle;\n    }\n\n'
    javaClassBuffer += generateJavaFunctionList(parsed[className])
    javaClassBuffer += generateNativeJavaFunctionList(parsed[className])
    javaClassBuffer += '    protected long nativeHandle;\n'
    javaClassBuffer += '};\n'
    jniBuffer += generateNativeFunctionList(className, parsed[className])

  print(javaClassBuffer)
  print(jniBuffer)

print('Generaing JNI for ' + sys.argv[1] + ' to ' + sys.argv[2])
generateJNI(sys.argv[1], sys.argv[2]) 

#print(str(parsed))
