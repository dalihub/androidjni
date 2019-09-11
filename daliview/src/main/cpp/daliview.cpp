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
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <android/configuration.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>

#include <dali/public-api/common/stage.h>
#include <dali/public-api/events/touch-point.h>
#include <dali/public-api/events/key-event.h>
#include <dali/public-api/adaptor-framework/application.h>
#include <dali/devel-api/adaptor-framework/application-devel.h>
#include <dali/integration-api/debug.h>

/// Application Event Enum
// Shared with enum in dali/internal/adaptor/android/framework-androidjni.cpp
enum
{
  APP_WINDOW_CREATED = 0,
  APP_WINDOW_DESTROYED,
  APP_PAUSE,
  APP_RESUME,
  APP_RESET,
  APP_LANGUAGE_CHANGE,
  APP_DESTROYED,
};

void ExtractAsset( AAssetManager* assetManager, std::string assetPath, std::string filePath )
{
  AAsset* asset = AAssetManager_open( assetManager, assetPath.c_str(), AASSET_MODE_BUFFER );
  if( asset )
  {
    size_t length = AAsset_getLength( asset ) + 1;

    char* buffer = new char[ length ];
    length = AAsset_read( asset, buffer, length );

    FILE* file = fopen( filePath.c_str(), "wb" );
    if( file )
    {
      fwrite( buffer, 1, length, file );
      fclose( file );
    }

    delete[] buffer;
    AAsset_close( asset );
  }
}

void ExtractAssetsDir( AAssetManager* assetManager, std::string assetDirPath, std::string filesDirPath )
{
  AAssetDir* assetDir = AAssetManager_openDir( assetManager, assetDirPath.c_str() );
  if( assetDir )
  {
    if( mkdir( filesDirPath.c_str(), S_IRWXU ) != -1 )
    {
      const char *filename = NULL;
      std::string assetPath = assetDirPath + "/";
      while ( ( filename = AAssetDir_getNextFileName( assetDir ) ) != NULL )
      {
        ExtractAsset( assetManager, assetPath + filename, filesDirPath + "/" + filename );
      }
    }

    AAssetDir_close( assetDir );
  }
}

void ExtractFontConfig( AAssetManager* assetManager, std::string assetFontConfig, std::string fontsPath )
{
  AAsset* asset = AAssetManager_open( assetManager, assetFontConfig.c_str(), AASSET_MODE_BUFFER );
  if( asset )
  {
    size_t length = AAsset_getLength( asset ) + 1;

    char* buffer = new char[ length ];
    length = AAsset_read( asset, buffer, length );

    std::string fontConfig = std::string( buffer, length );
    int i = fontConfig.find("<dir></dir>");
    if( i != std::string::npos )
      fontConfig.replace( i + strlen("<dir>"), 0, fontsPath );

    i = fontConfig.find("<cachedir></cachedir>");
    if( i != std::string::npos )
      fontConfig.replace( i + strlen("<cachedir>"), 0, fontsPath );

    std::string fontsFontConfig = fontsPath + "/fonts.conf";
    FILE* file = fopen( fontsFontConfig.c_str(), "wb" );
    if( file )
    {
      fwrite( fontConfig.c_str(), 1, fontConfig.size(), file );
      fclose( file );
    }

    delete[] buffer;
    AAsset_close( asset );
  }
}

extern "C" void FcConfigPathInit(const char* path, const char* file);

extern "C" JNIEXPORT jlong JNICALL Java_com_sec_daliview_DaliView_nativeOnConfigure(JNIEnv* jenv, jobject obj, jobject assetManager, jstring filesPath )
{
  DALI_LOG_ERROR( "nativeOnStart" );
  Dali::DevelApplication::SetApplicationContext( jenv );

  AAssetManager* am = AAssetManager_fromJava( jenv, assetManager );
  Dali::DevelApplication::SetApplicationAssets( am );

  struct stat st = { 0 };
  const char* cstr = jenv->GetStringUTFChars( filesPath, nullptr );
  std::string filesDir = std::string( cstr );
  jenv->ReleaseStringUTFChars( filesPath, cstr );

  std::string fontconfigPath = filesDir + "/fonts";
  setenv( "FONTCONFIG_PATH", fontconfigPath.c_str(), 1 );
  std::string fontconfigFile = fontconfigPath + "/fonts.conf";
  setenv( "FONTCONFIG_FILE", fontconfigFile.c_str(), 1 );
  FcConfigPathInit( fontconfigPath.c_str(), fontconfigFile.c_str() );

  if( stat( fontconfigPath.c_str(), &st ) == -1 )
  {
    mkdir( fontconfigPath.c_str(), S_IRWXU );
    ExtractFontConfig( am, "fonts/fonts.conf", fontconfigPath );
    ExtractAssetsDir( am, "fonts/dejavu", fontconfigPath + "/dejavu" );
    ExtractAssetsDir( am, "fonts/tizen", fontconfigPath + "/tizen" );
  }

  AConfiguration* configuration = AConfiguration_new();
  AConfiguration_fromAssetManager( configuration, am );
  Dali::DevelApplication::SetApplicationConfiguration( configuration );
}

extern "C" JNIEXPORT jlong JNICALL Java_com_sec_daliview_DaliView_nativeOnCreate(JNIEnv* jenv, jobject obj)
{
  // Default, creates empty app
  Dali::Application application = Dali::Application::New( 0, NULL );
  return reinterpret_cast<jlong>( application.GetObjectPtr() );
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_daliview_DaliView_nativeOnResume(JNIEnv* jenv, jobject obj, jlong handle)
{
  DALI_LOG_ERROR( "nativeOnResume" );

  if( handle )
  {
    Dali::RefObject* refObject = reinterpret_cast<Dali::RefObject*>( handle );
    Dali::Application application = Dali::DevelApplication::DownCast( refObject );
    Dali::DevelApplication::AppEventHandler( application, APP_RESUME, nullptr );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_daliview_DaliView_nativeOnPause(JNIEnv* jenv, jobject obj, jlong handle)
{
  DALI_LOG_ERROR("nativeOnPause");

  if( handle )
  {
    Dali::RefObject* refObject = reinterpret_cast<Dali::RefObject*>( handle );
    Dali::Application application = Dali::DevelApplication::DownCast( refObject );
    Dali::DevelApplication::AppEventHandler( application, APP_PAUSE, nullptr );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_daliview_DaliView_nativeOnFinalize(JNIEnv* jenv, jobject obj, jlong handle)
{
  DALI_LOG_ERROR( "nativeOnStop" );

  if( handle )
  {
    Dali::RefObject* refObject = reinterpret_cast<Dali::RefObject*>( handle );
    Dali::Application application = Dali::DevelApplication::DownCast( refObject );
    Dali::DevelApplication::AppEventHandler( application, APP_DESTROYED, nullptr );
    AConfiguration* configuration = static_cast<AConfiguration*>( Dali::DevelApplication::GetApplicationConfiguration() );
    if( configuration )
    {
      Dali::DevelApplication::SetApplicationConfiguration( nullptr );
      AConfiguration_delete( configuration );
    }

    Dali::DevelApplication::SetApplicationAssets( nullptr );
  }
}

extern "C" JNIEXPORT void JNICALL Java_com_sec_daliview_DaliView_nativeSetSurface(JNIEnv* jenv, jobject obj, jlong handle, jobject surface)
{
  DALI_LOG_ERROR( "nativeSetSurface" );
  if( handle )
  {
    Dali::RefObject* refObject = reinterpret_cast<Dali::RefObject*>( handle );
    Dali::Application application = Dali::DevelApplication::DownCast( refObject );

    ANativeWindow* oldWindow = static_cast<ANativeWindow*>( Dali::DevelApplication::GetApplicationWindow() );
    ANativeWindow* window = nullptr;
    if( surface )
    {
      window = ANativeWindow_fromSurface(jenv, surface);
    }

    if( window != oldWindow )
    {
      if( window )
      {
        Dali::DevelApplication::AppEventHandler( application, APP_WINDOW_CREATED, window );
      }
      else
      {
        Dali::DevelApplication::AppEventHandler( application, APP_DESTROYED, nullptr );
      }
    }

    if( oldWindow )
    {
      ANativeWindow_release( oldWindow );
    }
  }
}
