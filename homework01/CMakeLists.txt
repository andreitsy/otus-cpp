cmake_minimum_required(VERSION 3.20)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(VERSION_LIB lib.cpp lib.h)
set(GOOGLETEST_VERSION "1")
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

configure_file(version.h.in version.h @ONLY)

project(helloworld VERSION ${PROJECT_VERSION})

add_subdirectory(./googletest)
include_directories(./googletest/include ./googletest)
enable_testing()
add_library(version_lib ${VERSION_LIB})
target_include_directories(version_lib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(tests)

add_executable(helloworld_cli main.cpp)
target_link_libraries(helloworld_cli version_lib)

target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
        )
target_include_directories(helloworld_cli PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}")

# CPack package
set(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "andrei.tsypilnikov92@gmail.com")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT andrei.tsypilnikov92@gmail.com)

include(CPack)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)
