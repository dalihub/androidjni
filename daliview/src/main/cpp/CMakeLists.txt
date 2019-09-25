cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -frtti -w -Wall -std=gnu++11")

# DALi
set(DALI_ANDROID "${CMAKE_CURRENT_SOURCE_DIR}/../../../../dali")
include_directories(${DALI_ANDROID}/include)
include_directories(${DALI_ANDROID}/include/dali)

add_library(dali
        SHARED
        IMPORTED )

set_target_properties(dali
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/lib/${ANDROID_ABI}/libdali.so )

add_library(dalicore
        SHARED
        IMPORTED )

set_target_properties(dalicore
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ANDROID}/lib/${ANDROID_ABI}/libdali-core.so )

add_library(daliview SHARED
        daliview.cpp)

# Include libraries needed for daliview lib
target_link_libraries(daliview
                      dali
                      dalicore
                      android
                      EGL
                      GLESv3)
