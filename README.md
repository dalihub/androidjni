DALi Android JNI
================

This uses the new [Android Studio CMake plugin](http://tools.android.com/tech-docs/external-c-builds) with C++ support.
For how to use Android Studio, refer to [Andrid Studio CMake](https://codelabs.developers.google.com/codelabs/android-studio-cmake/index.html)

Pre-requisites
--------------
- Android Studio with [NDK](https://developer.android.com/ndk/) bundle.

Getting Started
---------------
1. Download [Android Studio](http://developer.android.com/sdk/index.html).
   * Choose Linux (64-bit) version of on Linux.
   * Extract Studio in path/to/studio.
   * Run: path/to/studio/android-studio/bin/studio.sh.
   * Install SDK in path/to/sdk.
   * Choose standard installation, leave default components checked, download.
2. Install the Android NDK:
   * In the Android studio window, go to *Configure* -> *SDK Manager*, check Android SDK Location: path/to/sdk. You will use this for the ANDROID_SDK environment variable later on.
   * Download Android NDK following instructions in the [Download the NDK and Tools](https://developer.android.com/ndk/guides#download-ndk) section only.
   * Once installed, note the NDK path for the environment variable later on. path/to/ndk is the folder containing ndk-build. Usually, it is path/to/sdk/ndk-bundle.
3. Create a folder called **dali** and then change to that folder. Currently, it is important that you call it **dali**.
4. Clone the following repos in this folder from https://github.com/dalihub/:
   * **dali-core**, checkout branch **devel/master**, tag **dali_1.4.38**.
   * **dali-adaptor**, checkout branch **devel/android**.
   * **dali-toolkit**, checkout branch **devel/master**, tag **dali_1.4.38**.
   * **android-dependencies**, checkout branch **master**.
   * **androidjni**, checkout branch **master_daliview_with_native_daliapp**.
5. Export build environment variables:
   ```
   export NDK=path/to/ndk
   export ANDROID_NDK=$NDK
   export ANDROID_SDK=path/to/sdk
   ```
6. Update androidjni/local.properties
   ```
   sdk.dir=path/to/sdk
   ndk.dir=path/to/ndk
   ```
7. If you have a proxy update androidjni/gradle.properties
   ```
   #http proxy setup
   systemProp.http.proxyHost=<proxy host>
   systemProp.http.proxyPort=<proxy port>

   #https proxy setup
   systemProp.https.proxyHost=<proxy host>
   systemProp.https.proxyPort=<proxy port>
   ```
8. Launch the studio after setting the enviroment variables: path/to/studio/android-studio/bin/studio.sh.
   * Import androidjni project from dali/androidjni folder using AndroidStudio.
   * Wait for downloading gradle and gradle sync to finish. It might take around 5 min.
   * Choose *Make Project*. Should build everything including dependencies and libraries, might take up to 15 min the first time.

