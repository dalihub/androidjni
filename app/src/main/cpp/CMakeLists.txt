cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -frtti -w -Wall -std=gnu++11")

# DALi
set(DALI_ANDROID "${CMAKE_CURRENT_SOURCE_DIR}/../../../../dali")
include_directories(${DALI_ANDROID}/include)
include_directories(${DALI_ANDROID}/include/dali)

add_library(dalicore
        SHARED
        IMPORTED )

set_target_properties(dalicore
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/lib/${ANDROID_ABI}/libdali-core.so )

add_library(dali
        SHARED
        IMPORTED )

set_target_properties(dali
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/lib/${ANDROID_ABI}/libdali.so )

add_library(daliview
        SHARED
        IMPORTED )

set(DALIVIEW "${CMAKE_CURRENT_SOURCE_DIR}/../../../../daliview")
string(TOLOWER ${CMAKE_BUILD_TYPE} build_type)
set_target_properties(daliview
        PROPERTIES IMPORTED_LOCATION
        ${DALIVIEW}/build/intermediates/cmake/${build_type}/obj/${ANDROID_ABI}/libdaliview.so )

add_library(dalidemo SHARED
        dalidemo.cpp)

# Include libraries needed
target_link_libraries(dalidemo
                      daliview
                      dali
                      dalicore
                      android
                      EGL
                      GLESv3
                      log)
