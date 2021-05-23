cmake_minimum_required(VERSION 3.5)

project(elftest LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
    find_program(IWYU_COMMAND NAMES include-what-you-use iwyu)
    if(NOT IWYU_COMMAND)
        message(FATAL_ERROR "include-what-you-use is not found!")
    else()
        set(CMAKE_C_INCLUDE_WHAT_YOU_USE "${IWYU_COMMAND};-Xiwyu;--verbose=1;-Xiwyu;--cxx17ns;-Xiwyu;--max_line_length=150;-Xiwyu;--output=fixes.cpp;-w")
    endif()
endif()
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(elftest main.c)
target_include_directories(elftest PRIVATE /insilications/apps/rpm-4.14.2.1 /insilications/apps/rpm-4.14.2.1/include/ /insilications/apps/rpm-4.14.2.1/misc/)

set(PUBLIC_LIBRARIES -lnss3 -lbz2 -lz -lelf -llzma -lzstd -lpopt -lcap -lacl -llua5.3 -lm -ldb -llmdb -ldl -lpthread /insilications/apps/rpm-4.14.2.1/rpmio/.libs/librpmio.so /insilications/apps/rpm-4.14.2.1/lib/.libs/librpm.so)
target_link_libraries(elftest PUBLIC ${PUBLIC_LIBRARIES})

set_property(TARGET elftest PROPERTY EXPORT_COMPILE_COMMANDS ON)

target_compile_definitions (elftest PUBLIC HAVE_CONFIG_H LOCALEDIR="\"/usr/share/locale\"" SYSCONFDIR="\"/usr/etc\"" LOCALSTATEDIR="\"/usr/var\"")
target_compile_options(elftest PUBLIC
    $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-g -Og -march=native -mtune=native -fPIC -Wpedantic -Wall -Wextra -Wno-c11-extensions -std=c++17 -pthread>
    $<$<COMPILE_LANG_AND_ID:C,Clang>:-g -Og -march=native -mtune=native -fPIC -Wpedantic -Wall -Wextra -Wno-c11-extensions -std=c17 -pthread>
    $<$<COMPILE_LANG_AND_ID:CXX,GNU>:-g -Og -march=native -mtune=native -fPIC -Wall -Wextra -fuse-ld=bfd -fuse-linker-plugin -pipe -ffat-lto-objects -std=c++17 -pthread>
    $<$<COMPILE_LANG_AND_ID:C,GNU>:-g -Og -march=native -mtune=native -fPIC -Wall -Wextra -fuse-ld=bfd -fuse-linker-plugin -pipe -ffat-lto-objects -std=c17 -pthread>
    )

target_link_options(elftest PUBLIC
    $<$<CXX_COMPILER_ID:Clang>:-g -Og -march=native -mtune=native -fPIC -Wpedantic -Wall -Wextra -Wno-c11-extensions -fuse-ld=lld -pthread -lpthread>
    $<$<CXX_COMPILER_ID:GNU>:-g3 -Og -march=native -mtune=native -fPIC -Wall -Wextra -fuse-ld=bfd -fuse-linker-plugin -pipe -ffat-lto-objects -pthread -lpthread>
    )

# use, i.e. don't skip the full RPATH for the build tree
set(CMAKE_SKIP_BUILD_RPATH FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# the RPATH to be used when installing, but only if it's not a system directory
list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
if("${isSystemDir}" STREQUAL "-1")
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
endif("${isSystemDir}" STREQUAL "-1")

