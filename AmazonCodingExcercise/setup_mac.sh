#!/bin/bash

chmod -R 777 ./thirdparty

thirdparty/cmake/mac/CMake.app/Contents/bin/cmake -S thirdparty/sdl -B thirdparty/sdl/build/mac/debug -DCMAKE_INSTALL_PREFIX=thirdparty/sdl/install/mac -DCMAKE_BUILD_TYPE=Debug
thirdparty/cmake/mac/CMake.app/Contents/bin/cmake -S thirdparty/sdl -B thirdparty/sdl/build/mac/release -DCMAKE_INSTALL_PREFIX=thirdparty/sdl/install/mac -DCMAKE_BUILD_TYPE=RelWithDebInfo

thirdparty/cmake/mac/CMake.app/Contents/bin/cmake --build thirdparty/sdl/build/mac/debug --target install
thirdparty/cmake/mac/CMake.app/Contents/bin/cmake --build thirdparty/sdl/build/mac/release --target install

thirdparty/cmake/mac/CMake.app/Contents/bin/cmake -S asteroids -G Xcode -B build/mac -DCMAKE_PREFIX_PATH=$(pwd)/thirdparty/sdl/install/mac

thirdparty/cmake/mac/CMake.app/Contents/bin/cmake --build build/mac --config Debug
thirdparty/cmake/mac/CMake.app/Contents/bin/cmake --build build/mac --config RelWithDebInfo
