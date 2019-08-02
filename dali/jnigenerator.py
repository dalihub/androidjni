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
                'Property::Index' : 'int',
                'Padding' : 'Rect', }

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
  functionPattern = re.compile('\n  (static\s+)?(const\s+)?(?P<returnType>[A-Za-z0-9_:]+)\s+(?P<functionName>[A-Za-z0-9_:]+)\(\s*(?P<argsList>.*)\s*\)(\s+const)?(;|({.*\n}))')
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

autoConversionTypes = { 'void',
                             'bool',
                             'int',
                             'long',
                             'float',
                             'double',
                             'uint8_t',
                             'uint16_t',
                             'uint32_t',
                             'uint64_t',
                             'int8_t',
                             'int16_t',
                             'int32_t',
                             'int64_t',
                             'Property::Index' }

def generateCPPFunctionArgsList(parsedArgsList):
  stringBuffer = ''
  for i in range(1, len(parsedArgsList)):
    arg = parsedArgsList[i]
    argType = str(arg[0])
    autoConversionType = argType in autoConversionTypes
    argType = argType.replace('std::', '')
    argType = argType.replace('Dali::', '')
    argType = argType.replace('::', '')
    argTypeInstance = argType[0].lower() + argType[1:]
    cppArgType = arg[0]
    #TODO for all std types
    if cppArgType != 'std::string':
      cppArgType = 'Dali::' + cppArgType
    if i != 1:
      if not autoConversionType:
        stringBuffer += ', ' + 'convertToCPP' + argType + '( jenv, ' + arg[2] + ' )'
        jniConversionUtils['convertToCPP' + argType] = cppArgType + ' ' + 'convertToCPP'+ argType + '( JNIEnv* jenv, jobject ' + argTypeInstance + ' )\n{\n}\n\n'
      else:
        stringBuffer += ', ' + arg[2]
    else:
      if not autoConversionType:
        stringBuffer += 'convertToCPP' + argType + '( jenv, ' + arg[2] + ' )'
        jniConversionUtils['convertToCPP' + argType] = cppArgType + ' ' + 'convertToCPP'+ argType + '( JNIEnv* jenv, jobject ' + argTypeInstance + ' )\n{\n}\n\n'
      else:
        stringBuffer += arg[2]
  return stringBuffer

def generateNativeFunction(packageName, className, functionName, parsedArgsList):
  stringBuffer = ''
  returnArg = parsedArgsList[0]
  returnArgType = str(returnArg[0])
  returnArgInstance = returnArgType[0].lower() + returnArgType[1:]
  returnArgInstance = returnArgInstance.replace('::', '')
  autoConversionType = returnArgType in autoConversionTypes
  classInstance = className[0].lower() + className[1:]
  stringBuffer += 'extern "C" JNIEXPORT ' + cppToJNIType(returnArgType) + ' JNICALL Java_com_sec_dali' + '_' + packageName +'_' + className + '_native' + functionName
  stringBuffer += '(JNIEnv* jenv, jobject obj, jlong handle'
  for i in range(1, len(parsedArgsList)):
    arg = parsedArgsList[i]
    if arg[2] != '':
      stringBuffer += ', ' + cppToJNIType(arg[0]) + ' ' + arg[2]
  stringBuffer += ')\n'
  stringBuffer += '{\n'
  stringBuffer += '  if( handle )\n'
  stringBuffer += '  {\n'
  stringBuffer += '    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );\n'
  stringBuffer += '    Dali::' + className + ' ' + classInstance + ' = Dali::'+className+'::DownCast( baseObject );\n'
  if returnArgType != 'void':
    if not autoConversionType:
        stringBuffer += '    Dali::' + returnArgType + ' ' + returnArgInstance + ' = ' + classInstance + '.' + functionName + '( ' + generateCPPFunctionArgsList(parsedArgsList) + ' );\n'
        stringBuffer += '    return convertToJNI' + returnArgType.replace('::','') + '( jenv, ' + returnArgInstance + ' );\n'
        jniConversionUtils['convertToJNI' + returnArgType] = 'jobject convertToJNI'+ returnArgType.replace('::','') + '( JNIEnv* jenv, Dali::' + returnArgType + ' ' + returnArgInstance + ' )\n{\n}\n\n'
    else:
      stringBuffer += '    return ' + classInstance + '.' + functionName + '( ' + generateCPPFunctionArgsList(parsedArgsList) + ' );\n'
  else:
    stringBuffer += '    ' + classInstance + '.' + functionName + '( ' + generateCPPFunctionArgsList(parsedArgsList) + ' );\n'
  stringBuffer += '  }\n'
  stringBuffer += '}\n'
  return stringBuffer

def generateNativeFunctionList(packageName, className, parsedFunctions):
  stringBuffer = ''
  packageName.replace('.', '_')
  for functionName in parsedFunctions:
    if functionName == 'DownCast':
      continue
    stringBuffer += generateNativeFunction(packageName, className, functionName, parsedFunctions[functionName]) + "\n";
  return stringBuffer

def getPackageName(path):
  packageName = re.sub('.*-api/', '', path)
  packageName = re.sub('\/.*\.h', '', packageName)
  packageName = re.sub('\/', '.', packageName)
  return packageName

javaFileBuffer = ''
jniConversionUtils = {}

def generateJNI(headerFilePath, generatedFilePath):
  file = open(headerFilePath, 'r')
  buffer = file.read()
  file.close()

  packageName = getPackageName(headerFilePath)
  className = ''
  baseClassList = ''
  classBody = ''
  jniFileBuffer = ''
  jniConversionUtilsFileBuffer = ''

  m = re.search('(class|struct)\s+DALI_[A-Za-z0-9_]+_API\s+(?P<className>[A-Za-z0-9_]+)(?P<baseClassList>\s*:(\s+(public|protected|private)\s+[A-Za-z0-9_]+,?))?\s*{(?P<classBody>(.|\n)*)};', buffer) 
  if m:
    className = m.group('className')
    classBody = m.group('classBody')
    if m.group('baseClassList') is not None:
      baseClassList = m.group('baseClassList')
    parsed[className] = {}
    parseFunctionsList(classBody, parsed[className])

  for className in parsed:
    javaFileBuffer = 'package com.sec.dali.' + packageName + ';\n'
    javaFileBuffer += '\n' 
    baseClassName = ''
    if baseClassList != '':
      m = re.search('(public|protected|private)\s+(?P<baseClassName>[A-Za-z0-9_]+)', baseClassList)
      if m:
        baseClassName = m.group('baseClassName')
    javaFileBuffer += 'public class ' + className + ' ' + ('extends ' if baseClassName != '' else '') + baseClassName +' {\n'
    javaFileBuffer += '    public ' + className + '( long nativeHandle ) {\n'
    javaFileBuffer += '        this.nativeHandle = nativeHandle;\n'
    javaFileBuffer += '    }\n'
    javaFileBuffer += '\n'
    javaFileBuffer += generateJavaFunctionList(parsed[className])
    javaFileBuffer += generateNativeJavaFunctionList(parsed[className])
    javaFileBuffer += '    protected long nativeHandle;\n'
    javaFileBuffer += '};\n'

    jniFileBuffer += generateNativeFunctionList(packageName, className, parsed[className])
    #print(javaFileBuffer)
    for jniConversionUtil in jniConversionUtils.values():
      jniConversionUtilsFileBuffer += jniConversionUtil
    print(jniConversionUtilsFileBuffer)
    print(jniFileBuffer)

print('Generaing JNI for ' + sys.argv[1] + ' to ' + sys.argv[2])
generateJNI(sys.argv[1], sys.argv[2]) 


#print(str(parsed))

