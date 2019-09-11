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
fi

if [ ! -d ./include ]; then
TARGET=x86_64 API=25 make headers
TARGET=armeabi-v7a API=25 make headers
fi

TARGET=x86_64 API=25 make $@
TARGET=armeabi-v7a API=25 make $@
