cmake_minimum_required(VERSION 3.12)

project(helloworld VERSION ${PROJECT_VESRION})

add_executable(helloworld_cli main.cpp)

set_target_properties(helloworld_cli PROPERTIES
    CXX_STANDARD 14
)

target_compile_options(helloworld_cli PRIVATE
    -Wall -Wextra -pedantic -Werror
)

