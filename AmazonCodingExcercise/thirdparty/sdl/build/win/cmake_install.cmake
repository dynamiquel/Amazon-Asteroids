# Install script for directory: S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/install/win")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/Debug/SDL2-staticd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/Release/SDL2-static.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/MinSizeRel/SDL2-static.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/RelWithDebInfo/SDL2-static.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/Debug/SDL2d.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/Release/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/MinSizeRel/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/RelWithDebInfo/SDL2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/Debug/SDL2d.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/Release/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/MinSizeRel/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/RelWithDebInfo/SDL2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/Debug/SDL2maind.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/Release/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/MinSizeRel/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/RelWithDebInfo/SDL2main.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake"
         "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/CMakeFiles/Export/cmake/SDL2Targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/CMakeFiles/Export/cmake/SDL2Targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/CMakeFiles/Export/cmake/SDL2Targets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/CMakeFiles/Export/cmake/SDL2Targets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/CMakeFiles/Export/cmake/SDL2Targets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/CMakeFiles/Export/cmake/SDL2Targets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/SDL2Config.cmake"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/SDL2ConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_assert.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_atomic.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_audio.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_bits.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_blendmode.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_clipboard.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_android.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_iphoneos.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_macosx.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_minimal.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_os2.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_pandora.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_psp.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_windows.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_winrt.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_config_wiz.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_copying.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_cpuinfo.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_egl.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_endian.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_error.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_events.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_filesystem.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_gamecontroller.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_gesture.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_haptic.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_hints.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_joystick.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_keyboard.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_keycode.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_loadso.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_log.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_main.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_messagebox.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_metal.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_mouse.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_mutex.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_name.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_opengl.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_opengl_glext.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_opengles.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_opengles2.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_opengles2_gl2.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_opengles2_gl2ext.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_opengles2_gl2platform.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_opengles2_khrplatform.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_pixels.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_platform.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_power.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_quit.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_rect.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_render.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_revision.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_rwops.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_scancode.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_sensor.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_shape.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_stdinc.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_surface.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_system.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_syswm.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_assert.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_common.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_compare.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_crc32.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_font.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_fuzzer.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_harness.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_images.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_log.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_md5.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_memory.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_test_random.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_thread.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_timer.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_touch.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_types.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_version.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_video.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/SDL_vulkan.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/begin_code.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/include/close_code.h"
    "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/include/SDL_config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "S:/Users/Liamk/Development/Games/AmazonCodingExcercise/AmazonCodingExcercise/thirdparty/sdl/build/win/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
