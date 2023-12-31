#[[
Copyright (c) 2023 Anthony I. Jackson, Alchemy2D Engine

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgment in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
]]
cmake_minimum_required(VERSION 3.0.0...3.5.0)
project(Alchemy2D)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/CMake")

set(ROOT_CMAKE_LIST_DIR ${CMAKE_CURRENT_LIST_DIR})

set(ALCHEMY_DEPENDENCIES_DIR
    "${CMAKE_CURRENT_LIST_DIR}/Dependencies/Third-Party/")
set(ALCHEMY_DEPENDENCIES_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/Dependencies")

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n"
  )
endif()

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Source")


add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Examples")
