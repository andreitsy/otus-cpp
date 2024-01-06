add_executable(unit_tests version_test.cpp)
target_link_libraries(unit_tests gtest_main version_lib)
target_include_directories(version_lib PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME unit_tests
         COMMAND unit_tests)