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
#include "jniutils.h"

Dali::Quaternion convertToCPPQuaternion( JNIEnv* jenv, jobject quaternion )
{
}

Dali::Vector4 convertToCPPVector4( JNIEnv* jenv, jobject vector4 )
{
  jclass clazz = jenv->GetObjectClass( vector4 );
  return Dali::Vector4( jenv->GetFloatField( clazz, jenv->GetFieldID( clazz, "x", "F" ) ),
                        jenv->GetFloatField( clazz, jenv->GetFieldID( clazz, "y", "F" ) ),
                        jenv->GetFloatField( clazz, jenv->GetFieldID( clazz, "z", "F" ) ),
                        jenv->GetFloatField( clazz, jenv->GetFieldID( clazz, "w", "F" ) ) );
}

Dali::Vector3 convertToCPPVector3( JNIEnv* jenv, jobject vector3 )
{
  jclass clazz = jenv->GetObjectClass( vector3 );
  return Dali::Vector3( jenv->GetFloatField( clazz, jenv->GetFieldID( clazz, "x", "F" ) ),
                        jenv->GetFloatField( clazz, jenv->GetFieldID( clazz, "y", "F" ) ),
                        jenv->GetFloatField( clazz, jenv->GetFieldID( clazz, "z", "F" ) ) );
}

Dali::Vector2 convertToCPPVector2( JNIEnv* jenv, jobject vector2 )
{
  jclass clazz = jenv->GetObjectClass( vector2 );
  return Dali::Vector2( jenv->GetFloatField( clazz, jenv->GetFieldID( clazz, "x", "F" ) ),
                        jenv->GetFloatField( clazz, jenv->GetFieldID( clazz, "y", "F" ) ) );
}

std::string convertToCPPString( JNIEnv* jenv, jstring jstr )
{
  const char* cstr = jenv->GetStringUTFChars( jstr, nullptr );
  std::string str = std::string( cstr );
  jenv->ReleaseStringUTFChars( jstr, cstr );
  return str;
}

jobject convertToJNIQuaternion( JNIEnv* jenv, Dali::Quaternion quaternion )
{
}

jobject convertToJNIMatrix( JNIEnv* jenv, Dali::Matrix matrix )
{
}

jobject convertToJNIVector4( JNIEnv* jenv, Dali::Vector4 vector4 )
{
  jclass clazz = jenv->FindClass( "com/sec/dali/math/Vector4" );
  jmethodID constructor = jenv->GetMethodID( clazz, "Vector4", "(FFFF)" );
  return jenv->NewObject( clazz, constructor, vector4.x, vector4.y, vector4.z, vector4.w );
}

jobject convertToJNIVector3( JNIEnv* jenv, Dali::Vector3 vector3 )
{
  jclass clazz = jenv->FindClass( "com/sec/dali/math/Vector3" );
  jmethodID constructor = jenv->GetMethodID( clazz, "Vector3", "(FFF)" );
  return jenv->NewObject( clazz, constructor, vector3.x, vector3.y, vector3.z );
}

jobject convertToJNIVector2( JNIEnv* jenv, Dali::Vector2 vector2 )
{
  jclass clazz = jenv->FindClass( "com/sec/dali/math/Vector2" );
  jmethodID constructor = jenv->GetMethodID( clazz, "Vector2", "(FF)" );
  return jenv->NewObject( clazz, constructor, vector2.x, vector2.y );
}

