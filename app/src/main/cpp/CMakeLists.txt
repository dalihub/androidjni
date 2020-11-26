cmake_minimum_required(VERSION 3.4.1)

SET(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions -frtti -w -Wall")

# DALi
set(DALI_ENV_DIR $ENV{DALI_ENV_DIR})
set(ENV{PKG_CONFIG_PATH} "${DALI_ENV_DIR}/lib/${ANDROID_ABI}/pkgconfig:$ENV{PKG_CONFIG_PATH}")
find_package(PkgConfig REQUIRED)

include_directories(${DALI_ENV_DIR}/include)
include_directories(${DALI_ENV_DIR}/include/dali)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  set(ENABLE_TRACE ON)
else()
  set(ENABLE_TRACE OFF)
endif()

if (EXISTS "${DALI_ENV_DIR}")
  pkg_check_modules(DALI_CORE dali2-core REQUIRED NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH)
  pkg_check_modules(DALI_ADAPTOR dali2-adaptor REQUIRED NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH)
  pkg_check_modules(DALI_TOOLKIT dali2-toolkit REQUIRED NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH)
else()
  message(WARNING "${DALI_ENV_DIR} not found!")
endif()

add_library(daliview SHARED
        IMPORTED)

set_target_properties(daliview
        PROPERTIES IMPORTED_LOCATION
        ${DALI_ENV_DIR}/lib/${ANDROID_ABI}/libdaliview.so )

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
