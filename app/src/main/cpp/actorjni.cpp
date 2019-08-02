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
#include <dali/public-api/actors/actor.h>

jobject convertToJNISizeScalePolicyType( Dali::SizeScalePolicy::Type sizeScalePolicyType )
{
}

jobject convertToJNIDrawModeType( JNIEnv* jenv, Dali::DrawMode::Type drawModeType )
{
}

Dali::Dimension::Type convertToCPPDimensionType( JNIEnv* jenv, jobject dimensionType )
{
}

Dali::SizeScalePolicy::Type convertToCPPSizeScalePolicyType( JNIEnv* jenv, jobject sizeScalePolicyType )
{
}

Dali::Actor convertToCPPActor( JNIEnv* jenv, jobject actor )
{
}

jobject convertToJNIColorMode( JNIEnv* jenv, Dali::ColorMode colorMode )
{
}

jobject convertToJNIResizePolicyType( JNIEnv* jenv, Dali::ResizePolicy::Type resizePolicyType )
{
}

Dali::ResizePolicy::Type convertToCPPResizePolicyType( JNIEnv* jenv, jobject resizePolicyType )
{
}

Dali::ColorMode convertToCPPColorMode( JNIEnv* jenv, jobject colorMode )
{
}

Dali::Padding convertToCPPPadding( JNIEnv* jenv, jobject padding )
{
}

Dali::DrawMode::Type convertToCPPDrawModeType( JNIEnv* jenv, jobject drawModeType )
{
}

jobject convertToJNIPadding( JNIEnv* jenv, Dali::Padding padding )
{
}

jobject convertToJNIActor( JNIEnv* jenv, Dali::Actor actor )
{
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeRaise(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.Raise();
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetPadding(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Padding padding;
    actor.GetPadding( padding );
    return convertToJNIPadding( jenv, padding );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeIsVisible(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.IsVisible();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeRaiseAbove(JNIEnv* jenv, jobject obj, jlong handle, jobject target)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.RaiseAbove( convertToCPPActor( jenv, target) );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentWorldOrientation(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Quaternion quaternion = actor.GetCurrentWorldOrientation();
    return convertToJNIQuaternion( jenv, quaternion );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetVisible(JNIEnv* jenv, jobject obj, jlong handle, jboolean visible)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetVisible( visible );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetSizeModeFactor(JNIEnv* jenv, jobject obj, jlong handle, jobject factor)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetSizeModeFactor( convertToCPPVector3( jenv,factor) );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeIsScaleInherited(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.IsScaleInherited();
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetTargetSize(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetTargetSize();
    return convertToJNIVector3( jenv, vector3 );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentColor(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector4 vector4 = actor.GetCurrentColor();
    return convertToJNIVector4( jenv, vector4 );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetScale(JNIEnv* jenv, jobject obj, jlong handle, jobject scale)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetScale( convertToCPPVector3( jenv, scale) );
  }
}

extern "C" JNIEXPORT jfloat JNICALL Java_com_sec_dali_actors_Actor_nativeGetRelayoutSize(JNIEnv* jenv, jobject obj, jlong handle, jobject dimension)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.GetRelayoutSize( convertToCPPDimensionType( jenv, dimension) );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentScale(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetCurrentScale();
    return convertToJNIVector3( jenv, vector3 );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeIsLayer(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.IsLayer();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeUnparent(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.Unparent();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetName(JNIEnv* jenv, jobject obj, jlong handle, jstring name)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetName( convertToCPPString( jenv, name ) );
  }
}

extern "C" JNIEXPORT jfloat JNICALL Java_com_sec_dali_actors_Actor_nativeGetWidthForHeight(JNIEnv* jenv, jobject obj, jlong handle, jfloat height)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.GetWidthForHeight( height );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetColorMode(JNIEnv* jenv, jobject obj, jlong handle, jobject colorMode)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetColorMode( convertToCPPColorMode( jenv, colorMode ) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetSensitive(JNIEnv* jenv, jobject obj, jlong handle, jboolean sensitive)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetSensitive( sensitive );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetX(JNIEnv* jenv, jobject obj, jlong handle, jfloat x)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetX( x );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetY(JNIEnv* jenv, jobject obj, jlong handle, jfloat y)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetY( y );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetZ(JNIEnv* jenv, jobject obj, jlong handle, jfloat z)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetZ( z );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentWorldMatrix(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Matrix matrix = actor.GetCurrentWorldMatrix();
    return convertToJNIMatrix( jenv, matrix );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetParent(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Actor parent = actor.GetParent();
    return convertToJNIActor( jenv, parent );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentPosition(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetCurrentPosition();
    return convertToJNIVector3( jenv, vector3 );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeFindChildByName(JNIEnv* jenv, jobject obj, jlong handle, jstring actorName)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Actor child = actor.FindChildByName( convertToCPPString( jenv, actorName ) );
    return convertToJNIActor( jenv, child );
  }
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_actors_Actor_nativeGetChildCount(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.GetChildCount();
  }
}

extern "C" JNIEXPORT jlong JNICALL Java_com_sec_dali_actors_Actor_nativeNew(JNIEnv* jenv, jobject obj)
{
  Dali::Handle handle = Dali::Actor::New();
  return reinterpret_cast<jlong>( &handle.GetBaseObject() );
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetMinimumSize(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector2 vector2 = actor.GetMinimumSize();
    return convertToJNIVector2( jenv, vector2 );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetParentOrigin(JNIEnv* jenv, jobject obj, jlong handle, jobject origin)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetParentOrigin( convertToCPPVector3( jenv, origin ) );
  }
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_actors_Actor_nativeGetRendererCount(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.GetRendererCount();
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetChildAt(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Actor child = actor.GetChildAt( index );
    return convertToJNIActor( jenv, actor );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetResizePolicy(JNIEnv* jenv, jobject obj, jlong handle, jobject dimension)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::ResizePolicy::Type resizePolicyType = actor.GetResizePolicy( convertToCPPDimensionType( jenv, dimension ) );
    return convertToJNIResizePolicyType( jenv, resizePolicyType );
  }
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_actors_Actor_nativeGetHierarchyDepth(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.GetHierarchyDepth();
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeGetLeaveRequired(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.GetLeaveRequired();
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetDrawMode(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::DrawMode::Type drawModeType = actor.GetDrawMode();
    return convertToJNIDrawModeType( jenv, drawModeType );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeRemove(JNIEnv* jenv, jobject obj, jlong handle, jobject child)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.Remove( convertToCPPActor( jenv, child ) );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeIsOrientationInherited(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.IsOrientationInherited();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetLeaveRequired(JNIEnv* jenv, jobject obj, jlong handle, jboolean required)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetLeaveRequired( required );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetAnchorPoint(JNIEnv* jenv, jobject obj, jlong handle, jobject anchorPoint)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetAnchorPoint( convertToCPPVector3( jenv, anchorPoint ) );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentSize(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetCurrentSize();
    return convertToJNIVector3( jenv, vector3 );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetMinimumSize(JNIEnv* jenv, jobject obj, jlong handle, jobject size)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetMinimumSize( convertToCPPVector2( jenv, size) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetResizePolicy(JNIEnv* jenv, jobject obj, jlong handle, jobject policy, jobject dimension)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetResizePolicy( convertToCPPResizePolicyType( jenv, policy), convertToCPPDimensionType( jenv,dimension) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetMaximumSize(JNIEnv* jenv, jobject obj, jlong handle, jobject size)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetMaximumSize( convertToCPPVector2( jenv,size) );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeOnStage(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.OnStage();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetOrientation(JNIEnv* jenv, jobject obj, jlong handle, jobject orientation)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetOrientation( convertToCPPQuaternion( jenv, orientation ) );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeIsKeyboardFocusable(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.IsKeyboardFocusable();
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetColorMode(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::ColorMode colorMode = actor.GetColorMode();
    return convertToJNIColorMode( jenv, colorMode );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeFindChildById(JNIEnv* jenv, jobject obj, jlong handle, jint id)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Actor child = actor.FindChildById( id );
    return convertToJNIActor( jenv, child );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentAnchorPoint(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetCurrentAnchorPoint();
    return convertToJNIVector3( jenv, vector3 );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentWorldScale(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetCurrentWorldScale();
    return convertToJNIVector3( jenv, vector3 );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeAdd(JNIEnv* jenv, jobject obj, jlong handle, jobject child)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.Add( convertToCPPActor( jenv, child ) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetColor(JNIEnv* jenv, jobject obj, jlong handle, jobject color)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetColor( convertToCPPVector4( jenv, color ) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetKeyboardFocusable(JNIEnv* jenv, jobject obj, jlong handle, jboolean focusable)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetKeyboardFocusable( focusable );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetInheritScale(JNIEnv* jenv, jobject obj, jlong handle, jboolean inherit)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetInheritScale( inherit );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetSizeScalePolicy(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::SizeScalePolicy::Type sizeScalePolicyType = actor.GetSizeScalePolicy();
    return convertToJNISizeScalePolicyType( sizeScalePolicyType );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentOrientation(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Quaternion quaternion = actor.GetCurrentOrientation();
    return convertToJNIQuaternion( jenv, quaternion );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetOpacity(JNIEnv* jenv, jobject obj, jlong handle, jfloat opacity)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetOpacity( opacity );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeLowerBelow(JNIEnv* jenv, jobject obj, jlong handle, jobject target)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.LowerBelow( convertToCPPActor( jenv, target ) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetPadding(JNIEnv* jenv, jobject obj, jlong handle, jobject padding)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetPadding( convertToCPPPadding( jenv, padding ) );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetSizeModeFactor(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetSizeModeFactor();
    return convertToJNIVector3( jenv, vector3 );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeIsRoot(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.IsRoot();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeLowerToBottom(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.LowerToBottom();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetInheritOrientation(JNIEnv* jenv, jobject obj, jlong handle, jboolean inherit)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetInheritOrientation( inherit );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetSizeScalePolicy(JNIEnv* jenv, jobject obj, jlong handle, jobject policy)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetSizeScalePolicy( convertToCPPSizeScalePolicyType( jenv, policy ) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetDrawMode(JNIEnv* jenv, jobject obj, jlong handle, jobject drawMode)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetDrawMode( convertToCPPDrawModeType( jenv, drawMode ) );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeRaiseToTop(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.RaiseToTop();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeScaleBy(JNIEnv* jenv, jobject obj, jlong handle, jobject relativeScale)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.ScaleBy( convertToCPPVector3( jenv, relativeScale ) );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetNaturalSize(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetNaturalSize();
    return convertToJNIVector3( jenv, vector3 );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetSize(JNIEnv* jenv, jobject obj, jlong handle, jobject size)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetSize( convertToCPPVector3( jenv, size ) );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeScreenToLocal(JNIEnv* jenv, jobject obj, jlong handle, jfloat localX, jfloat localY, jfloat screenX, jfloat screenY)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.ScreenToLocal( localX, localY, screenX, screenY );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeTranslateBy(JNIEnv* jenv, jobject obj, jlong handle, jobject distance)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.TranslateBy( convertToCPPVector3( jenv, distance ) );
  }
}

extern "C" JNIEXPORT jfloat JNICALL Java_com_sec_dali_actors_Actor_nativeGetHeightForWidth(JNIEnv* jenv, jobject obj, jlong handle, jfloat width)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.GetHeightForWidth( width );
  }
}

extern "C" JNIEXPORT jfloat JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentOpacity(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.GetCurrentOpacity();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeLower(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.Lower();
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentWorldPosition(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetCurrentWorldPosition();
    return convertToJNIVector3( jenv, vector3 );
  }
}

extern "C" JNIEXPORT jboolean JNICALL Java_com_sec_dali_actors_Actor_nativeIsSensitive(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.IsSensitive();
  }
}

extern "C" JNIEXPORT jint JNICALL Java_com_sec_dali_actors_Actor_nativeGetId(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    return actor.GetId();
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeRotateBy(JNIEnv* jenv, jobject obj, jlong handle, jobject relativeRotation)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.RotateBy( convertToCPPQuaternion( jenv, relativeRotation ) );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetMaximumSize(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector2 vector2 = actor.GetMaximumSize();
    return convertToJNIVector2( jenv, vector2 );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeRemoveRenderer(JNIEnv* jenv, jobject obj, jlong handle, jint index)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.RemoveRenderer( index );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_dali_actors_Actor_nativeSetPosition(JNIEnv* jenv, jobject obj, jlong handle, jobject position)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    actor.SetPosition( convertToCPPVector3( jenv, position ) );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentWorldColor(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector4 vector4 = actor.GetCurrentWorldColor();
    return convertToJNIVector4( jenv, vector4 );
  }
}

extern "C" JNIEXPORT jobject JNICALL Java_com_sec_dali_actors_Actor_nativeGetCurrentParentOrigin(JNIEnv* jenv, jobject obj, jlong handle)
{
  if( handle )
  {
    Dali::BaseObject *baseObject = reinterpret_cast<Dali::BaseObject*>( handle );
    Dali::Actor actor = Dali::Actor::DownCast( baseObject );
    Dali::Vector3 vector3 = actor.GetCurrentParentOrigin();
    return convertToJNIVector3( jenv, vector3 );
  }
}

