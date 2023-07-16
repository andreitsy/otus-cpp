cmake_minimum_required(VERSION 3.20)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
configure_file(version.h.in version.h @ONLY)

project(helloworld VERSION ${PROJECT_VERSION})
add_executable(helloworld_cli main.cpp version.cpp)

set_target_properties(helloworld_cli PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
)
target_include_directories(helloworld_cli PRIVATE
        "${CMAKE_CURRENT_BINARY_DIR}")

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT andrei.tsypilnikov92@gmail.com)

include(CPack)
