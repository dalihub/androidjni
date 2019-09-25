
if [ -d ./dali-core/cmake/${TARGET} ]
then
cd ./dali-core/cmake/${TARGET}
else
mkdir -p ./dali-core/cmake/${TARGET}
cd ./dali-core/cmake/${TARGET}
~/Android/Sdk/cmake/3.10.2.4988404/bin/cmake ../../../../../dali-core/build/tizen -DCMAKE_C_COMPILER=~/Android/Sdk/ndk-bundle/toolchains/llvm/prebuilt/linux-x86_64/bin/clang -DCMAKE_CXX_COMPILER=~/Android/Sdk/ndk-bundle/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ -DCMAKE_INSTALL_PREFIX=../../../dali-core/ -DCMAKE_TOOLCHAIN_FILE=~/Android/Sdk/ndk-bundle/build/cmake/android.toolchain.cmake -DANDROID_PLATFORM=24 -DANDROID_ABI=${TARGET} -DANDROID_NDK=${HOME}/Android/Sdk/ndk-bundle -DANDROID_STL=c++_shared -DCMAKE_CXX_FLAGS='-fexceptions -frtti -w -Wall -std=gnu++11' -DINCLUDE_DIR=../include -DLIB_DIR=lib/${TARGET} -DCMAKE_BUILD_TYPE=$@
fi
make
make install
cd -