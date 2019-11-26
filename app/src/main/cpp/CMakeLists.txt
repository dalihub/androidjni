cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -frtti -w -Wall -std=gnu++11")

# DALi
get_filename_component(DALI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../../.." ABSOLUTE)
set(ANDROID_SDK $ENV{ANDROID_SDK})
set(ANDROID_NDK $ENV{ANDROID_NDK})

set(ENV{PKG_CONFIG_PATH}  "${DALI_DIR}/dali-env/android/lib/${ANDROID_ABI}/pkgconfig:$ENV{PKG_CONFIG_PATH}")
find_package(PkgConfig REQUIRED)

include_directories(${DALI_DIR}/dali-env/android/include)
include_directories(${DALI_DIR}/dali-env/android/include/dali)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  set(ENABLE_TRACE ON)
else()
  set(ENABLE_TRACE OFF)
endif()

if (EXISTS "${DALI_DIR}/dali-env/android")
  pkg_check_modules(DALI_CORE dali-core REQUIRED NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH)
  pkg_check_modules(DALI_ADAPTOR dali-adaptor REQUIRED NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH)
  pkg_check_modules(DALI_TOOLKIT dali-toolkit NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH)
else()
  message(WARNING "Clean Project after first gradle sync!")
endif()

add_library(daliview SHARED
        IMPORTED)

set_target_properties(daliview
        PROPERTIES IMPORTED_LOCATION
        ${DALI_DIR}/dali-env/android/lib/${ANDROID_ABI}/libdaliview.so )

add_definitions(-DDEMO_IMAGE_DIR=\"assets/images/\")
add_definitions(-DDEMO_MODEL_DIR=\"assets/models/\")
add_library(dalidemo SHARED
        dalidemo.cpp)

# Include libraries needed
target_link_libraries(dalidemo
                      daliview
                      ${DALI_TOOLKIT_LDFLAGS}
                      ${DALI_ADAPTOR_LDFLAGS}
                      ${DALI_CORE_LDFLAGS}
                      android
                      EGL
                      GLESv3
                      log)
