cmake_minimum_required(VERSION 3.5)

project(elftest LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

#if (CMAKE_C_COMPILER_ID STREQUAL "Clang")
#    find_program(IWYU_COMMAND NAMES include-what-you-use iwyu)
#    if(NOT IWYU_COMMAND)
#        message(FATAL_ERROR "include-what-you-use is not found!")
#    else()
#        set(CMAKE_C_INCLUDE_WHAT_YOU_USE "${IWYU_COMMAND};-Xiwyu;--verbose=1;-Xiwyu;--cxx17ns;-Xiwyu;--max_line_length=150;-Xiwyu;--output=fixes.cpp;-w")
#    endif()
#endif()
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(elftest main.c)
target_include_directories(elftest PRIVATE /insilications/apps/rpm-4.14.2.1 /insilications/apps/rpm-4.14.2.1/include/ /insilications/apps/rpm-4.14.2.1/misc/)

set(PUBLIC_LIBRARIES -lnss3 -lnspr4 -lbz2 -lz -lelf -llzma -lzstd -lpopt -lcap -lacl -llua5.3 -lm -ldb -llmdb -ldl -lpthread /insilications/apps/rpm-4.14.2.1/rpmio/.libs/librpmio.so /insilications/apps/rpm-4.14.2.1/lib/.libs/librpm.so)
#set(PUBLIC_LIBRARIES -lnss3 -lnssutil3 -lplc4 -lplds4 -lnspr4 -lbz2 -lz -lelf -llzma -lzstd -lpopt -lcap -lacl /usr/lib64/liblua5.3.a -lm -ldb -llmdb -ldl -lpthread /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmio.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmrc.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmmalloc.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/digest_nss.o /insilications/apps/rpm-4.14.2.1/lib/.libs/poptALL.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/macro.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmlog.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmstring.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmsw.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmliblua.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmlua.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmfileutil.o /insilications/apps/rpm-4.14.2.1/luaext/.libs/libluaext_la-lposix.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmglob.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/argv.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/digest.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/url.o /insilications/apps/rpm-4.14.2.1/misc/.libs/fnmatch.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmdb.o /usr/lib64/liblua5.3.a /insilications/apps/rpm-4.14.2.1/lib/backend/.libs/dbi.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmts.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmtriggers.o /insilications/apps/rpm-4.14.2.1/lib/backend/.libs/dbiset.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmlock.o /insilications/apps/rpm-4.14.2.1/lib/.libs/header.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmplugins.o /insilications/apps/rpm-4.14.2.1/lib/.libs/depends.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmte.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmfs.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmfi.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmds.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmps.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmstrpool.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmsq.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmchroot.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmprob.o /insilications/apps/rpm-4.14.2.1/lib/.libs/tagname.o /insilications/apps/rpm-4.14.2.1/lib/backend/.libs/db3.o /insilications/apps/rpm-4.14.2.1/lib/backend/.libs/lmdb.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmprob.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmhook.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmug.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmkeyring.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/base64.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmvercmp.o /insilications/apps/rpm-4.14.2.1/lib/.libs/rpmal.o /insilications/apps/rpm-4.14.2.1/rpmio/.libs/rpmpgp.o /insilications/apps/rpm-4.14.2.1/lib/.libs/fprint.o /insilications/apps/rpm-4.14.2.1/lib/.libs/cpio.o /insilications/apps/rpm-4.14.2.1/luaext/.libs/libluaext_la-lrexlib.o)
target_link_libraries(elftest PUBLIC ${PUBLIC_LIBRARIES})

set_property(TARGET elftest PROPERTY EXPORT_COMPILE_COMMANDS ON)

target_compile_definitions (elftest PUBLIC WITH_LUA HAVE_CONFIG_H LOCALEDIR="\"/usr/share/locale\"" SYSCONFDIR="\"/usr/etc\"" LOCALSTATEDIR="\"/usr/var\"")
target_compile_options(elftest PUBLIC
    $<$<COMPILE_LANG_AND_ID:CXX,Clang>:-g -Og -march=native -mtune=native -fPIC -Wpedantic -Wall -Wextra -Wno-c11-extensions -std=c++17 -pthread>
    $<$<COMPILE_LANG_AND_ID:C,Clang>:-g -Og -march=native -mtune=native -fPIC -Wpedantic -Wall -Wextra -Wno-c11-extensions -std=c17 -pthread>
    $<$<COMPILE_LANG_AND_ID:CXX,GNU>: -g3 -Og -march=native -mtune=native -fPIC -Wall -Wextra -fuse-ld=bfd -fuse-linker-plugin -pipe -ffat-lto-objects -std=c++17 -pthread>
    $<$<COMPILE_LANG_AND_ID:C,GNU>:-g3 -Og -march=native -mtune=native -fPIC -Wall -Wextra -fuse-ld=bfd -fuse-linker-plugin -pipe -ffat-lto-objects -std=c17 -pthread>
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

