#cmake_minimum_required(VERSION 3.4.1)
#
#add_library( # Library name
#        native-lib
#        SHARED
#        native-lib.cpp )
#
#find_library( # Android log lib
#        log-lib
#        log )
#
#target_link_libraries( # Link native-lib with Android log
#        native-lib
#        ${log-lib} )
#
## Add googletest source
#add_subdirectory(googletest)
#
#add_executable(
#        unit_tests
#        test/gt-date.cpp
#)
#
## Link the test executable with gtest and gtest_main
#target_link_libraries(
#        unit_tests
#        gtest
#        gtest_main
#        ${log-lib}
#)
#
#set_property(TARGET unit_tests PROPERTY CXX_STANDARD 11)
# cd into build so pwd = MobileInventory/app/src/main/cpp/build
# cmake ..
# make
# ./all_tests --gtest_filter=
cmake_minimum_required(VERSION 3.10)
project(NativeLibTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Native code library
add_library(native-lib STATIC native-lib.cpp)

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