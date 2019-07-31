cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -frtti -w -Wall -std=gnu++11")
set(DALI_ANDROID "${CMAKE_CURRENT_SOURCE_DIR}/../../../../..")

# DALi
include_directories(${DALI_ANDROID}/dali-env/android/include)
include_directories(${DALI_ANDROID}/dali-env/android/include/dali)
include_directories(${DALI_ANDROID}/android-dependencies/libexif)
include_directories(${DALI_ANDROID}/android-dependencies/libfontconfig)
include_directories(${DALI_ANDROID}/android-dependencies/libfreetype)
include_directories(${DALI_ANDROID}/android-dependencies/libgif)
include_directories(${DALI_ANDROID}/android-dependencies/libjpeg-turbo)
include_directories(${DALI_ANDROID}/android-dependencies/libpng)

add_library(dali
        STATIC
        IMPORTED )

set_target_properties(dali
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/androidjni/dali/obj/local/${ANDROID_ABI}/libdali.a )

add_library(exif
        STATIC
        IMPORTED )

set_target_properties(exif
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/android-dependencies/libexif/obj/local/${ANDROID_ABI}/libexif.a )

add_library(freetype
        STATIC
        IMPORTED )

set_target_properties(freetype
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/android-dependencies/libfreetype/obj/local/${ANDROID_ABI}/libfreetype.a )

add_library(fontconfig
        STATIC
        IMPORTED )

set_target_properties(fontconfig
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/android-dependencies/libfontconfig/obj/local/${ANDROID_ABI}/libfontconfig.a )

add_library(harfbuzz
        STATIC
        IMPORTED )

set_target_properties(harfbuzz
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/android-dependencies/libharfbuzz/obj/local/${ANDROID_ABI}/libharfbuzz.a )

add_library(gif
        STATIC
        IMPORTED )

set_target_properties(gif
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/android-dependencies/libgif/obj/local/${ANDROID_ABI}/libgif.a )

add_library(jpeg-turbo
        STATIC
        IMPORTED )

set_target_properties(jpeg-turbo
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/android-dependencies/libjpeg-turbo/obj/local/${ANDROID_ABI}/libjpeg-turbo.a )

add_library(png
        STATIC
        IMPORTED )

set_target_properties(png
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/android-dependencies/libpng/obj/local/${ANDROID_ABI}/libpng.a )

add_library(daliviewjni SHARED
        daliviewjni.cpp
        handlejni.cpp)

# Include libraries needed for jnisurfaceview lib
target_link_libraries(daliviewjni
                      dali
                      android
                      EGL
                      GLESv3
                      z
                      exif
                      gif
                      jpeg-turbo
                      png
                      log
                      fontconfig
                      freetype
                      harfbuzz)
