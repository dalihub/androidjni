DALi Android JNI
=========

This uses the new [Android Studio CMake plugin](http://tools.android.com/tech-docs/external-c-builds) with C++ support.
For how to use Android Studio, refer to [Andrid Studio CMake] https://codelabs.developers.google.com/codelabs/android-studio-cmake/index.html)

Pre-requisites
--------------
- Android Studio with [NDK](https://developer.android.com/ndk/) bundle.

Getting Started
---------------
1. [Download Android Studio](http://developer.android.com/sdk/index.html)
    Choose Linux (64-bit) version of on Linux.
    Extract Studio in $installation-dir.
    Install SDK in $sdk-dir.
    Run: $installation-dir/android-studio/bin/studio.sh.
    Choose standard installation, leave default components checked, download.
2.  Go to *Configure* -> *SDK Manager*, check Android SDK Location: $sdk-dir.
    Download Android NDK following instructions from https://developer.android.com/ndk/guides, *Download the NDK and Tools*.
    Your $ndk-dir is the folder containing ndk-build. Usually, it is $sdk-dir/ndk-bundle.
3.  Create dali folder somewhere in your home directory, change to dali folder.
4.  Clone dali-core from https://github.com/dalihub/, checkout branch devel/master, tag dali_1.4.38.
5.  Clone dali-adaptor from https://github.com/dalihub/, checkout branch devel/android, latest.
6.  Clone dali-toolkit from https://github.com/dalihub/, checkout branch devel/master, tag dali_1.4.38.
7.  Clone android-dependencies from https://github.com/dalihub/, checkout branch master, latest.
8.  Clone androidjni from https://github.com/dalihub/, checkout branch master_daliview_with_native_daliapp, latest.
9.  Export build env variables:
```
       export NDK=$ndk-dir
       export ANDROID_NDK=$NDK
       export ANDROID_SDK=$sdk-dir
```
10. Update androidjni/local.properties
```
       sdk.dir=$sdk-dir
       ndk.dir=$ndk-dir
```
11. Launch the studio with the env variables: $installation-dir/android-studio/bin/studio.sh.
    Import androidjni project from dali/androidjni folder using AndroidStudio.
    Wait for downloading gradle and gradle sync to finish.
    Choose *Make Project*.
    Should build everything including dependencies and libraries.

