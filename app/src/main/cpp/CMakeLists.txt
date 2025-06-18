cmake_minimum_required(VERSION 3.4.1)

add_library( # Library name
        native-lib
        SHARED
        native-lib.cpp )

find_library( # Android log lib
        log-lib
        log )

target_link_libraries( # Link native-lib with Android log
        native-lib
        ${log-lib} )
