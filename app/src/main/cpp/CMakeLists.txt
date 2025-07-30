# cd into build so pwd = MobileInventory/app/src/main/cpp/build
# Choose which one. One doesn't have the flags enabled other does
# cmake ..
#   make
#   ./test-all
# cmake -DENABLE_COVERAGE=ON ..
#   make
#   ./test_all
#   make coverage
#   open coverage_report/index.html
#

# ./all_tests --gtest_filter=
cmake_minimum_required(VERSION 3.14)
project(NativeLibTest)

option(ENABLE_COVERAGE "Enable coverage reporting" OFF)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ENABLE_COVERAGE)
    set(ENV{GCOV} "gcov-15")
    message(STATUS "Coverage enabled")
    add_compile_options(--coverage)
    add_link_options(--coverage)
    find_program(LCOV_PATH lcov)
    find_program(GENHTML_PATH genhtml)

    if(LCOV_PATH AND GENHTML_PATH)
        # Custom target to generate coverage report
        add_custom_target(coverage
                COMMAND ${LCOV_PATH} --directory . --capture --output-file coverage.info --ignore-errors inconsistent,unsupported
                COMMAND ${GENHTML_PATH} coverage.info --output-directory coverage_report
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                COMMENT "Generating coverage report with lcov and genhtml"
                VERBATIM
        )
    else()
        message(WARNING "lcov or genhtml not found! Coverage report won't be generated.")
    endif()
endif()

# Native code library
add_library(
        native-lib STATIC native-lib.cpp
)

add_library(
        InventoryMgmt
        SHARED
        InventoryMgmt.cpp
        sqlite3.c
)

# GoogleTest
add_subdirectory(googletest)

enable_testing()

# Unit test executable
add_executable(test_all gtest/gt_date.cpp)

# Link native-lib if needed by your test
target_link_libraries(test_all
        gtest
        gtest_main
        native-lib  # Optional, if your tests use native-lib
)

# Register the test with CTest
add_test(NAME AllTests COMMAND test_all)