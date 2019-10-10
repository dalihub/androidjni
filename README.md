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
   1.1. Choose Linux (64-bit) version of on Linux.
   1.2. Extract Studio in path/to/studio.
   1.3. Run: path/to/studio/android-studio/bin/studio.sh.
   1.4. Install SDK in path/to/sdk.
   1.5. Choose standard installation, leave default components checked, download.
2. Go to *Configure* -> *SDK Manager*, check Android SDK Location: path/to/sdk.
   Download Android NDK following instructions from https://developer.android.com/ndk/guides, *Download the NDK and Tools*.
   Your path/to/ndk is the folder containing ndk-build. Usually, it is path/to/sdk/ndk-bundle.
3. Create dali folder, change to dali folder.
4. Clone dali-core from https://github.com/dalihub/, checkout branch devel/master, tag dali_1.4.38.
5. Clone dali-adaptor from https://github.com/dalihub/, checkout branch devel/android, latest.
6. Clone dali-toolkit from https://github.com/dalihub/, checkout branch devel/master, tag dali_1.4.38.
7. Clone android-dependencies from https://github.com/dalihub/, checkout branch master, latest.
8. Clone androidjni from https://github.com/dalihub/, checkout branch master_daliview_with_native_daliapp, latest.
9. Export build env variables:
```
       export NDK=path/to/ndk
       export ANDROID_NDK=$NDK
       export ANDROID_SDK=path/to/sdk
```
10. Update androidjni/local.properties
```
       sdk.dir=path/to/sdk
       ndk.dir=path/to/ndk
```
11. if you have a proxy update androidjni/gradle.properties
```
       #http proxy setup
       systemProp.http.proxyHost=<proxy host>
       systemProp.http.proxyPort=<proxy port>

       #https proxy setup
       systemProp.https.proxyHost=<proxy host>
       systemProp.https.proxyPort=<proxy port>
```
12. Launch the studio after setting the enviroment variables: path/to/studio/android-studio/bin/studio.sh.
   12.1. Import androidjni project from dali/androidjni folder using AndroidStudio.
   12.2. Wait for downloading gradle and gradle sync to finish. It might take around 5 min.
   12.3. Choose *Make Project*. Should build everything including dependencies and libraries, might take up to 15 min the first time.

