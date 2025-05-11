add_executable(tests
    tests_main.cpp
    test_message.cpp
)

target_include_directories(tests
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(tests
    PRIVATE
        core_lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
