/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string.h>

#include <jni.h>

#include <dali/dali.h>
#include <dali/public-api/object/handle.h>
#include <dali/devel-api/object/handle-devel.h>
#include <dali/public-api/object/property-types.h>
#include <dali/public-api/object/property-value.h>

std::string getString(JNIEnv* jenv, jstring jstr)
{
  const char* cstr = jenv->GetStringUTFChars( jstr, nullptr );
  std::string str = std::string( cstr );
  jenv->ReleaseStringUTFChars( jstr, cstr );
  return str;
}

Dali::Property::Value getPropertyValue(JNIEnv* jenv, jobject propertyValue)
{
  jclass propertyValueClass = jenv->GetObjectClass(propertyValue);
  jmethodID methodId = jenv->GetMethodID(propertyValueClass, "getType", "()Lcom/sec/dali/object/Property/Type;");
  jobject propertyType = (jobject)jenv->CallObjectMethod(propertyValueClass, methodId);
  jclass propertyTypeClass = jenv->GetObjectClass(propertyType);
  jfieldID fieldId = jenv->GetFieldID(propertyTypeClass, "type", "I");
  int type = jenv->GetIntField(propertyTypeClass, fieldId);

  switch (type) {
    case 0:// None
      return Dali::Property::Value();
    case 1: {
      methodId = jenv->GetMethodID(propertyValueClass, "getBoolean", "()Z");
      jboolean value = jenv->CallBooleanMethod(propertyValueClass, methodId);
      return Dali::Property::Value(value ? true : false);
      break;
    }
    case 2: {
      methodId = jenv->GetMethodID(propertyValueClass, "getFloat", "()F");
      jfloat value = jenv->CallFloatMethod(propertyValueClass, methodId);
      return Dali::Property::Value(value);
      break;
    }
    case 3: {
      methodId = jenv->GetMethodID(propertyValueClass, "getInteger", "()I");
      jint value = (jint)jenv->CallIntMethod(propertyValueClass, methodId);
      return Dali::Property::Value(value);
      break;
    }
    case 4: {
      methodId = jenv->GetMethodID(propertyValueClass, "getFloatArray", "()[F");
      jfloatArray value = (jfloatArray)jenv->CallObjectMethod(propertyValueClass, methodId);
      jfloat* array = jenv->GetFloatArrayElements(value, 0);
      Dali::Vector2 vec2( array[0], array[1] );
      jenv->ReleaseFloatArrayElements(value, array, 0);
      return Dali::Property::Value(vec2);
      break;
    }
    case 5: {
      methodId = jenv->GetMethodID(propertyValueClass, "getFloatArray", "()[F");
      jfloatArray value = (jfloatArray)jenv->CallObjectMethod(propertyValueClass, methodId);
      jfloat* array = jenv->GetFloatArrayElements(value, 0);
      Dali::Vector3 vec3( array[0], array[1], array[2] );
      jenv->ReleaseFloatArrayElements(value, array, 0);
      return Dali::Property::Value(vec3);
      break;
    }
    case 6: {
      methodId = jenv->GetMethodID(propertyValueClass, "getFloatArray", "()[F");
      jfloatArray value = (jfloatArray)jenv->CallObjectMethod(propertyValueClass, methodId);
      jfloat* array = jenv->GetFloatArrayElements(value, 0);
      Dali::Vector4 vec4( array[0], array[1], array[2], array[3] );
      jenv->ReleaseFloatArrayElements(value, array, 0);
      return Dali::Property::Value(vec4);
      break;
    }
  }
  return Dali::Property::Value();
}

jobject newPropertyValue(JNIEnv* jenv, Dali::Property::Value& propertyValue)
{
// TODO
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_object_Handle_nativeGetPropertyIndex(JNIEnv* jenv, jobject obj, jlong handle, jstring name)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    return handle.GetPropertyIndex( getString( jenv, name ) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_object_Handle_nativeRemovePropertyNotifications(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    return handle.RemovePropertyNotifications();
  }
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_object_Handle_nativeGetPropertyCount(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    return handle.GetPropertyCount();
  }
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_object_Handle_nativeRegisterProperty(JNIEnv* jenv, jobject obj, jlong handle, jstring name, jobject propertyValue, jint accessMode)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    handle.RegisterProperty(getString(jenv, name), getPropertyValue(jenv, propertyValue));
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_object_Handle_nativeIsPropertyWritable(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    return handle.IsPropertyWritable(index) ? 1 : 0;
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_object_Handle_nativeGetCurrentProperty(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    Dali::Property::Value value = handle.GetCurrentProperty(index);
    return newPropertyValue(jenv, value);
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_object_Handle_nativeRemoveConstraints(JNIEnv* jenv, jobject obj, jlong handle, jint tag)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    handle.RemoveConstraints(tag);
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_object_Handle_nativeSetProperty(JNIEnv* jenv, jobject obj, jlong handle, jint index, jobject propertyValue)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    handle.SetProperty( index, getPropertyValue( jenv, propertyValue ) );
  }
}

extern "C" JNIEXPORT jstring JNICALL Java_com_sec_dali_object_Handle_nativeGetPropertyName(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    return jenv->NewStringUTF(handle.GetPropertyName(index).c_str());
  }

  return jenv->NewStringUTF("");
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_object_Handle_nativeIsPropertyAnimatable(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::RefObject *refObject = reinterpret_cast<Dali::RefObject *>( handle );
    Dali::Handle handle = Dali::DevelHandle::DownCast( refObject );
    return handle.IsPropertyAnimatable( index ) ? 1 : 0;
  }

  return 0;
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_object_Handle_nativeGetPropertyType(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{

}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_object_Handle_nativeGetProperty(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{

}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_object_Handle_nativeIsPropertyAConstraintInput(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{

}

