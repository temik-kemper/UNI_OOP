cmake_minimum_required(VERSION 3.0.0)
project(lesson_03 VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)

message(SOURCES="${SOURCES}")
add_executable(lesson_03 src/main.cpp ${SOURCES})
