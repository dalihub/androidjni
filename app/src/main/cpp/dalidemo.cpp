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

#include <jni.h>

#include <dali-toolkit/dali-toolkit.h>

using namespace Dali;
using Dali::Toolkit::TextLabel;

// This example shows how to create and display Hello World! using a simple TextActor
//
class HelloWorldController : public ConnectionTracker
{
public:

  HelloWorldController( Application& application )
          : mApplication( application )
  {
    // Connect to the Application's Init signal
    mApplication.InitSignal().Connect( this, &HelloWorldController::Create );
  }

  ~HelloWorldController()
  {
    // Nothing to do here;
  }

  // The Init signal is received once (only) during the Application lifetime
  void Create( Application& application )
  {
    // Get a handle to the stage
    Stage stage = Stage::GetCurrent();
    stage.SetBackgroundColor( Color::WHITE );

    TextLabel textLabel = TextLabel::New( "Hello World" );
    textLabel.SetAnchorPoint( AnchorPoint::TOP_LEFT );
    textLabel.SetName( "helloWorldLabel" );
    stage.Add( textLabel );

    // Respond to a click anywhere on the stage
    stage.GetRootLayer().TouchSignal().Connect( this, &HelloWorldController::OnTouch );

    // Respond to key events
    stage.KeyEventSignal().Connect( this, &HelloWorldController::OnKeyEvent );
  }

  bool OnTouch( Actor actor, const TouchData& touch )
  {
    // quit the application
    mApplication.Quit();
    return true;
  }

  void OnKeyEvent( const KeyEvent& event )
  {
    if( event.state == KeyEvent::Down )
    {
      if ( IsKey( event, Dali::DALI_KEY_ESCAPE ) || IsKey( event, Dali::DALI_KEY_BACK ) )
      {
        mApplication.Quit();
      }
    }
  }

private:
  Application&  mApplication;
};

jlong OnCreate(JNIEnv* jenv, jobject obj)
{
  Application application = Application::New( 0, NULL );
  HelloWorldController test( application );
  reinterpret_cast<jlong>( application.GetObjectPtr() );
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
  JNIEnv* env;
  if (vm->GetEnv(reinterpret_cast<void**>( &env ), JNI_VERSION_1_6) != JNI_OK) {
    return JNI_ERR;
  }

  // Find your class. JNI_OnLoad is called from the correct class loader context for this to work.
  jclass c = env->FindClass("com/sec/daliview/DaliView");
  if (c == nullptr)
    return JNI_ERR;

  // Register your class' native methods.
  static const JNINativeMethod methods[] = {
          { "nativeOnCreate", "()L", reinterpret_cast<JNINativeMethod*>(OnCreate) },
  };

  int rc = env->RegisterNatives(c, methods, sizeof(methods)/sizeof(JNINativeMethod));
  if (rc != JNI_OK)
    return rc;

  return JNI_VERSION_1_6;
}



