#!/bin/bash
if [ -z "$NDK" ]; then
  . ./env.sh
fi

if [ ! -d "$ANDROID_SDK" ]; then
  echo "Please install Android SDK into "$ANDROID_SDK
  exit 1
fi

if [ ! -d "$ANDROID_NDK" ]; then
  echo "Please install Android NDK into "$ANDROID_NDK
  exit 1
fi

if [ "$1" = "clean" ]; then
echo "Cleaning dali..."
rm -rf ./include
rm -rf ./lib
rm -rd ./dali-core
exit 0
fi

if [ ! -d ./include ]; then
TARGET=x86_64 API=25 make headers
TARGET=armeabi-v7a API=25 make headers
echo -e "#include <string>\n\nstd::string GetSystemCachePath() { return \"\"; }\n" > ../../dali-adaptor/dali/internal/adaptor/common/system-cache-path.cpp
fi

if [ -z "$DEBUG" ]; then
TARGET=x86_64 ./build_core.sh Release
TARGET=armeabi-v7a ./build_core.sh Release
else
TARGET=x86_64 ./build_core.sh Debug
TARGET=armeabi-v7a ./build_core.sh Debug
fi

TARGET=x86_64 API=25 make $@
TARGET=armeabi-v7a API=25 make $@
