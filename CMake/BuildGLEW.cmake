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
set(GLEW_VERSION 2.2.0)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_UTILS OFF CACHE BOOL "" FORCE)
set(GLEW_OSMESA OFF CACHE BOOL "" FORCE)
set(GLEW_REGAL OFF CACHE BOOL "" FORCE)


if (NOT EXISTS "${ALCHEMY_DEPENDENCIES_DIR}/glew-${GLEW_VERSION}")
    if (WIN32)

    elseif (UNIX)
        message(FATAL_ERROR "Please run DownloadDependencies.sh from ${ALCHEMY_DEPENDENCIES_DIR}.")
    endif()
endif()

add_subdirectory("${ALCHEMY_DEPENDENCIES_DIR}/glew-${GLEW_VERSION}/build/cmake" "${ALCHEMY_DEPENDENCIES_BUILD_DIR}/glew")
