@echo off

REM Build SDL
thirdparty\cmake\win\bin\cmake -S thirdparty\sdl -B thirdparty\sdl\build\win -DCMAKE_INSTALL_PREFIX=thirdparty\sdl\install\win
thirdparty\cmake\win\bin\cmake --build thirdparty\sdl\build\win --config Debug --target install
thirdparty\cmake\win\bin\cmake --build thirdparty\sdl\build\win --config RelWithDebInfo --target install

REM Build project
thirdparty\cmake\win\bin\cmake -S asteroids -B build\win -DCMAKE_PREFIX_PATH="%cd%\thirdparty\sdl\install\win"
thirdparty\cmake\win\bin\cmake --build build\win --config Debug
thirdparty\cmake\win\bin\cmake --build build\win --config RelWithDebInfo
