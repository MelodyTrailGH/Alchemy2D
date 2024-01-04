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
project(
  Alchemy2D
  VERSION 1.0.0.0
  DESCRIPTION ""
  HOMEPAGE_URL ""
  LANGUAGES C CXX)


# ##############################################################################
# Misc.
# ##############################################################################
if (UNIX)
add_compile_options("$<$<CONFIG:DEBUG>:-D_DEBUG>")    #this will allow to use same _DEBUG macro available in both Linux as well as Windows - MSCV environment. Easy to put Debug specific code.
endif (UNIX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/CMake")

# ##############################################################################
# Alternative Names.
# ##############################################################################
if(${PROJECT_NAME}_USE_ALT_NAMES)
  string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
  string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)
else()
  set(PROJECT_NAME_LOWERCASE ${PROJECT_NAME})
  set(PROJECT_NAME_UPPERCASE ${PROJECT_NAME})
endif()

# ##############################################################################
# Getting sources.
# ##############################################################################
set(ALCHEMY_SOURCE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(ALCHEMY_INCLUDE_DIRECTORY ${ALCHEMY_SOURCE_DIRECTORY}/Include)
include(SourcesAndHeaders)


# ##############################################################################
# Configure target.
# ##############################################################################
set(ALCHEMY_TARGET_NAME "Alchemy2D")
add_library(${ALCHEMY_TARGET_NAME} STATIC ${ALCHEMY_SOURCES} ${ALCHEMY_PUBLIC_HEADERS})
target_include_directories(
  ${ALCHEMY_TARGET_NAME}
  PUBLIC $<BUILD_INTERFACE:${ALCHEMY_INCLUDE_DIRECTORY}>
         $<INSTALL_INTERFACE:include/${ALCHEMY_LIBRARY_NAME}>)

set_target_properties(
  ${ALCHEMY_TARGET_NAME}
  PROPERTIES OUTPUT_NAME ${ALCHEMY_TARGET_NAME}
             ARCHIVE_OUTPUT_DIRECTORY
             "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/Library"
             LIBRARY_OUTPUT_DIRECTORY
             "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/Library"
             RUNTIME_OUTPUT_DIRECTORY
             "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/Binaries")

target_compile_features(${ALCHEMY_TARGET_NAME} PUBLIC c_std_17)
target_compile_features(${ALCHEMY_TARGET_NAME} PUBLIC cxx_std_17)

set_target_properties(${ALCHEMY_TARGET_NAME} PROPERTIES
            C_STANDARD 17
            C_STANDARD_REQUIRED ON
            C_EXTENSIONS ON
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
            CXX_EXTENSIONS ON
)

include(StandardCompilerWarnings)
set_project_warnings(${ALCHEMY_TARGET_NAME})