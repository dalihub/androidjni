# version:
#   https://dl.google.com/android/repository/android-ndk-r19b-linux-x86_64.zip
#   https://dl.google.com/android/repository/cmake-3.10.2-linux-x86_64.zip
#   https://dl.google.com/android/repository/lldb-3.1.4508709-linux-x86_64.zip
# instructions from https://developer.android.com/ndk/guides/other_build_systems
export NDK=$HOME/Android/Sdk/ndk-bundle
export ANDROID_NDK=$NDK
export ANDROID_SDK=$HOME/Android/Sdk
export HOST_TAG=linux-x86_64
export TOOLCHAIN=$NDK/toolchains/llvm/prebuilt/$HOST_TAG
export AR=$TOOLCHAIN/bin/aarch64-linux-android-ar
export AS=$TOOLCHAIN/bin/aarch64-linux-android-as
export CC=$TOOLCHAIN/bin/aarch64-linux-android28-clang
export CXX=$TOOLCHAIN/bin/aarch64-linux-android28-clang++
export LD=$TOOLCHAIN/bin/aarch64-linux-android-ld
export RANLIB=$TOOLCHAIN/bin/aarch64-linux-android-ranlib
export STRIP=$TOOLCHAIN/bin/aarch64-linux-android-strip
export SYSROOT=$TOOLCHAIN/sysroot
export PATH=$TOOLCHAIN/bin:$PATH
export CFLAGS="--sysroot=$SYSROOT"
export CXXFLAGS="–sysroot=$SYSROOT"
export HOST=arm-linux-androideabi
