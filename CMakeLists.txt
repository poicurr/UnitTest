project(UnitTest)

set(UNIT_TEST_VERSION_MAJOR 0)
set(UNIT_TEST_VERSION_MINOR 0)
set(UNIT_TEST_VERSION_TEENY 1)
set(PACKAGE_VERSION "${UNIT_TEST_VERSION_MAJOR}.${UNIT_TEST_VERSION_MINOR}.${UNIT_TEST_VERSION_TEENY}")

cmake_minimum_required(VERSION 2.8)

add_subdirectory(src)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()

