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

#include "jniutils.h"

#include <dali/dali.h>
#include <dali/public-api/object/handle.h>
#include <dali/devel-api/object/handle-devel.h>
#include <dali/public-api/object/property-types.h>
#include <dali/public-api/object/property-value.h>

jint getEnumValue(JNIEnv* jenv, jobject jenum)
{
  jclass enumClass = jenv->GetObjectClass(jenum);
  jfieldID fieldId = jenv->GetFieldID(enumClass, "value", "I");
  return jenv->GetIntField(enumClass, fieldId);
}

Dali::Property::Value convertToCPPPropertyValue(JNIEnv *jenv, jobject propertyValue)
{
  jclass clazz = jenv->GetObjectClass(propertyValue);
  jmethodID getType = jenv->GetMethodID(clazz, "getType", "()Lcom/sec/dali/object/Property/Type;");
  jobject propertyType = (jobject)jenv->CallObjectMethod(clazz, getType);
  int type = getEnumValue(jenv, propertyType);

  switch (type) {
    case 0:// None
      return Dali::Property::Value();
    case 1:
    {
      jmethodID getBoolean = jenv->GetMethodID(clazz, "getBoolean", "()Z");
      jboolean value = jenv->CallBooleanMethod(clazz, getBoolean);
      return Dali::Property::Value(value ? true : false);
      break;
    }
    case 2:
    {
      jmethodID getFloat = jenv->GetMethodID(clazz, "getFloat", "()F");
      jfloat value = jenv->CallFloatMethod(clazz, getType);
      return Dali::Property::Value(value);
      break;
    }
    case 3:
    {
      jmethodID getInteger = jenv->GetMethodID(clazz, "getInteger", "()I");
      jint value = jenv->CallIntMethod(clazz, getInteger);
      return Dali::Property::Value(value);
      break;
    }
    case 4:
    {
      jmethodID getFloatArray = jenv->GetMethodID(clazz, "getFloatArray", "()[F");
      jfloatArray value = (jfloatArray)jenv->CallObjectMethod(clazz, getType);
      jfloat* array = jenv->GetFloatArrayElements(value, 0);
      Dali::Vector2 vec2( array[0], array[1] );
      jenv->ReleaseFloatArrayElements(value, array, 0);
      return Dali::Property::Value(vec2);
      break;
    }
    case 5:
    {
      jmethodID getFloatArray = jenv->GetMethodID(clazz, "getFloatArray", "()[F");
      jfloatArray value = (jfloatArray)jenv->CallObjectMethod(clazz, getType);
      jfloat* array = jenv->GetFloatArrayElements(value, 0);
      Dali::Vector3 vec3( array[0], array[1], array[2] );
      jenv->ReleaseFloatArrayElements(value, array, 0);
      return Dali::Property::Value(vec3);
      break;
    }
    case 6:
    {
      jmethodID getFloatArray = jenv->GetMethodID(clazz, "getFloatArray", "()[F");
      jfloatArray value = (jfloatArray)jenv->CallObjectMethod(clazz, getType);
      jfloat* array = jenv->GetFloatArrayElements(value, 0);
      Dali::Vector4 vec4( array[0], array[1], array[2], array[3] );
      jenv->ReleaseFloatArrayElements(value, array, 0);
      return Dali::Property::Value(vec4);
      break;
    }
  }

  return Dali::Property::Value();
}

jobject convertToJNIPropertyValue(JNIEnv* jenv, Dali::Property::Value propertyValue)
{
  switch( propertyValue.GetType() )
  {
    case Dali::Property::Type::BOOLEAN:
    {
      jclass clazz = jenv->FindClass("com/sec/dali/object/Property/BooleanValue");
      jmethodID constructor = jenv->GetMethodID(clazz, "BooleanValue", "(Z)");
      bool value = false;
      propertyValue.Get( value );
      jboolean jvalue = value ? 1 : 0;
      return jenv->NewObject(clazz, constructor, jvalue);
    }
    case Dali::Property::Type::INTEGER:
    {
      jclass clazz = jenv->FindClass("com/sec/dali/object/Property/IntegerValue");
      jmethodID constructor = jenv->GetMethodID(clazz, "IntegerValue", "(I)");
      int value = 0;
      propertyValue.Get( value );
      return jenv->NewObject(clazz, constructor, value);
    }
    case Dali::Property::Type::FLOAT:
    {
      jclass clazz = jenv->FindClass("com/sec/dali/object/Property/FloatValue");
      jmethodID constructor = jenv->GetMethodID(clazz, "FloatValue", "(F)");
      float value = 0.0f;
      propertyValue.Get( value );
      return jenv->NewObject(clazz, constructor, value);
    }
    case Dali::Property::Type::VECTOR2:
    {
      jclass clazz = jenv->FindClass("com/sec/dali/object/Property/Vector2Value");
      jmethodID constructor = jenv->GetMethodID(clazz, "Vector2Value", "(FF)");
      Dali::Vector2 value;
      propertyValue.Get( value );
      return jenv->NewObject(clazz, constructor, value.x, value.y);
    }
    case Dali::Property::Type::VECTOR3:
    {
      jclass clazz = jenv->FindClass("com/sec/dali/object/Property/Vector3Value");
      jmethodID constructor = jenv->GetMethodID(clazz, "Vector3Value", "(FFF)");
      Dali::Vector3 value;
      propertyValue.Get( value );
      return jenv->NewObject(clazz, constructor, value.x, value.y, value.z);
    }
    case Dali::Property::Type::VECTOR4:
    {
      jclass clazz = jenv->FindClass("com/sec/dali/object/Property/Vector4Value");
      jmethodID constructor = jenv->GetMethodID(clazz, "Vector4Value", "(FFFF)");
      Dali::Vector3 value;
      propertyValue.Get( value );
      return jenv->NewObject(clazz, constructor, value.x, value.y, value.z);
    }
    default:
    {
      jclass clazz = jenv->FindClass("com/sec/dali/object/Property/NoneValue");
      jmethodID constructor = jenv->GetMethodID(clazz, "NoneValue", "()");
      return jenv->NewObject(clazz, constructor);
    }
  }
}

jobject convertToJNIPropertyType(JNIEnv *jenv, Dali::Property::Type propertyType)
{
  jclass clazz = jenv->FindClass("com/sec/dali/object/Property/Type");
  jmethodID constructor = jenv->GetMethodID(clazz, "Type", "(I)");
  return jenv->NewObject(clazz, constructor, static_cast<jint>( propertyType ) );
}

extern "C" JNIEXPORT jlong JNICALL Java_com_sec_dali_object_Handle_nativeNewHandle(JNIEnv* jenv, jobject obj)
{
  Dali::Handle handle = Dali::Handle::New();
  return reinterpret_cast<jlong>( &handle.GetBaseObject() );
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_object_Handle_nativeGetPropertyIndex(JNIEnv* jenv, jobject obj, jlong handle, jstring name)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    return handle.GetPropertyIndex( convertToCPPString( jenv, name ) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_object_Handle_nativeRemovePropertyNotifications(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    return handle.RemovePropertyNotifications();
  }
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_object_Handle_nativeGetPropertyCount(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    return handle.GetPropertyCount();
  }
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_object_Handle_nativeRegisterProperty(JNIEnv* jenv, jobject obj, jlong handle, jstring name, jobject propertyValue, jobject accessMode)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    handle.RegisterProperty( convertToCPPString(jenv, name),
                             convertToCPPPropertyValue(jenv, propertyValue), static_cast<Dali::Property::AccessMode>( getEnumValue(jenv, accessMode) ));
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_object_Handle_nativeIsPropertyWritable(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    return handle.IsPropertyWritable(index);
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_object_Handle_nativeGetCurrentProperty(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    Dali::Property::Value value = handle.GetCurrentProperty(index);
    return convertToJNIPropertyValue(jenv, value);
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_object_Handle_nativeRemoveConstraints(JNIEnv* jenv, jobject obj, jlong handle, jint tag)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    handle.RemoveConstraints(tag);
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_object_Handle_nativeSetProperty(JNIEnv* jenv, jobject obj, jlong handle, jint index, jobject propertyValue)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    handle.SetProperty( index, convertToCPPPropertyValue(jenv, propertyValue) );
  }
}

extern "C" JNIEXPORT jstring JNICALL Java_com_sec_dali_object_Handle_nativeGetPropertyName(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    return jenv->NewStringUTF(handle.GetPropertyName(index).c_str());
  }

  return jenv->NewStringUTF( "" );
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_object_Handle_nativeIsPropertyAnimatable(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    return handle.IsPropertyAnimatable( index );
  }

  return 0;
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_object_Handle_nativeGetPropertyType(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    Dali::Property::Type propertyType = handle.GetPropertyType(index);
    return convertToJNIPropertyType( jenv, handle.GetPropertyType(index) );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_object_Handle_nativeGetProperty(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    return convertToJNIPropertyValue( jenv, handle.GetProperty(index) );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_object_Handle_nativeIsPropertyAConstraintInput(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::BaseObject* baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Handle handle = Dali::Handle::DownCast( baseObject );
    return handle.IsPropertyAConstraintInput( index );
  }
}

