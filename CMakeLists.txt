cmake_minimum_required(VERSION 3.10)

project(leetcode)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(STDIN_FILE_PATH="${CMAKE_SOURCE_DIR}/stdin.txt")
add_compile_definitions(LOCAL_ENV_LEETCODE)

# basic include
FILE(GLOB BASIC_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/basic/*)
message("-- basic include dir:")
foreach (dirpath ${BASIC_INCLUDE_DIR})
    message("--     ${dirpath}")
    include_directories(${dirpath})
endforeach ()

add_subdirectory(question)
add_subdirectory(algorithm)
