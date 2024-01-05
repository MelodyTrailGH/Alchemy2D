cmake_minimum_required(VERSION 3.0.0...3.5.0)
project(Monitor)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Alchemy2D::Alchemy2D)
