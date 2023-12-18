cmake_minimum_required(VERSION 3.1.9...3.5.0)
project(Playground)

add_executable(playground)
target_sources(playground PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Playground.cc")
target_link_libraries(playground PRIVATE Alchemy2D::Alchemy2D)
