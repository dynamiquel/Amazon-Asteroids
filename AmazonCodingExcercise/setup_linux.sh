#!/bin/bash

chmod -R 777 ./thirdparty

thirdparty/cmake/linux/bin/cmake -S thirdparty/sdl -B thirdparty/sdl/build/linux/debug -DCMAKE_INSTALL_PREFIX=thirdparty/sdl/install/linux -DCMAKE_BUILD_TYPE=Debug
thirdparty/cmake/linux/bin/cmake -S thirdparty/sdl -B thirdparty/sdl/build/linux/release -DCMAKE_INSTALL_PREFIX=thirdparty/sdl/install/linux -DCMAKE_BUILD_TYPE=RelWithDebInfo

thirdparty/cmake/linux/bin/cmake --build thirdparty/sdl/build/linux/debug --target install
thirdparty/cmake/linux/bin/cmake --build thirdparty/sdl/build/linux/release --target install

thirdparty/cmake/linux/bin/cmake -S asteroids -G "Unix Makefiles" -B build/linux/debug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=$(pwd)/thirdparty/sdl/install/linux
thirdparty/cmake/linux/bin/cmake -S asteroids -G "Unix Makefiles" -B build/linux/release -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_PREFIX_PATH=$(pwd)/thirdparty/sdl/install/linux

thirdparty/cmake/linux/bin/cmake --build build/linux/debug
thirdparty/cmake/linux/bin/cmake --build build/linux/release
