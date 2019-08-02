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
#ifndef ANDROIDJNI_JNIUTILS_H
#define ANDROIDJNI_JNIUTILS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string.h>

#include <jni.h>

#include <dali/dali.h>
#include <dali/public-api/math/vector2.h>
#include <dali/public-api/math/vector3.h>
#include <dali/public-api/math/vector4.h>
#include <dali/public-api/math/quaternion.h>
#include <dali/public-api/math/matrix.h>

// Dali
Dali::Quaternion convertToCPPQuaternion( JNIEnv* jenv, jobject quaternion );
Dali::Vector4 convertToCPPVector4( JNIEnv* jenv, jobject vector4 );
Dali::Vector3 convertToCPPVector3( JNIEnv* jenv, jobject vector3 );
Dali::Vector2 convertToCPPVector2( JNIEnv* jenv, jobject vector2 );

jobject convertToJNIQuaternion( JNIEnv* jenv, Dali::Quaternion quaternion );
jobject convertToJNIMatrix( JNIEnv* jenv, Dali::Matrix matrix );
jobject convertToJNIVector4( JNIEnv* jenv, Dali::Vector4 vector4 );
jobject convertToJNIVector3( JNIEnv* jenv, Dali::Vector3 vector3 );
jobject convertToJNIVector2( JNIEnv* jenv, Dali::Vector2 vector2 );

// std
std::string convertToCPPString( JNIEnv* jenv, jstring string );


#endif //ANDROIDJNI_JNIUTILS_H
