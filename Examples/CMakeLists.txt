cmake_minimum_required(VERSION 3.1.9...3.5.0)
project(Alchemy-Examples
    VERSION 1.0.0.0
    DESCRIPTION "A collection of example projects made with Alchemy2D."
    HOMEPAGE_URL ""
    LANGUAGES C CXX
)

message(STATUS "Examples enabled!")
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Playground")
