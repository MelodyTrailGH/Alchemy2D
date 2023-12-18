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

set(SDL_RELEASE 2)
set(SDL_RELEASE_VERSION 2.28.5)
set(SDL_DOWNLOAD_URI
    "https://github.com/libsdl-org/SDL/releases/download/release-${SDL_RELEASE_VERSION}/SDL${SDL_RELEASE}-${SDL_RELEASE_VERSION}.tar.gz"
)
set(SDL_ARCHIVE_FILE "SDL${SDL_RELEASE}-${SDL_RELEASE_VERSION}.tar.gz")
set(SDL_EXTRACT_FOLDER "SDL${SDL_RELEASE}-${SDL_RELEASE_VERSION}")

if(NOT EXISTS
   "${CMAKE_CURRENT_LIST_DIR}/SDL${SDL_RELEASE}-${SDL_RELEASE_VERSION}")

  message(STATUS "Downloading SDL${SDL_RELEASE} v${SDL_RELEASE_VERSION}...")

  file(DOWNLOAD ${SDL_DOWNLOAD_URI}
       ${CMAKE_CURRENT_LIST_DIR}/${SDL_ARCHIVE_FILE} SHOW_PROGRESS)

  message(
    STATUS
      "Downloaded \"${SDL_ARCHIVE_FILE}\" to \"${CMAKE_CURRENT_LIST_DIR}/${SDL_ARCHIVE_FILE}\"."
  )

  message(
    STATUS "Extracting \"${CMAKE_CURRENT_LIST_DIR}/${SDL_ARCHIVE_FILE}\"...")
  file(ARCHIVE_EXTRACT INPUT ${CMAKE_CURRENT_LIST_DIR}/${SDL_ARCHIVE_FILE}
       DESTINATION "${CMAKE_CURRENT_LIST_DIR}")
  message(
    STATUS
      "Extracted \"${CMAKE_CURRENT_LIST_DIR}/${SDL_ARCHIVE_FILE}\" to \"${CMAKE_CURRENT_LIST_DIR}/${SDL_EXTRACT_FOLDER}\""
  )

  if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/${SDL_ARCHIVE_FILE}")
    file(REMOVE "${CMAKE_CURRENT_LIST_DIR}/${SDL_ARCHIVE_FILE}")
  endif()
endif()

set(GLEW_VERSION 2.2.0)
set(GLEW_DOWNLOAD_URI
    "https://github.com/nigels-com/glew/releases/download/glew-${GLEW_VERSION}/glew-${GLEW_VERSION}.tgz"
)
set(GLEW_ARCHIVE_FILE "glew-${GLEW_VERSION}.tgz")
set(GLEW_EXTRACT_FOLDER "glew-${GLEW_VERSION}")
if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/${GLEW_EXTRACT_FOLDER}")

  # Downloading
  message(STATUS "Downloading GLEW v${GLEW_VERSION}...")
  file(DOWNLOAD "${GLEW_DOWNLOAD_URI}"
       "${CMAKE_CURRENT_LIST_DIR}/${GLEW_ARCHIVE_FILE}" SHOW_PROGRESS)
  message(
    STATUS
      "Downloaded \"${GLEW_ARCHIVE_FILE}\" to \"${CMAKE_CURRENT_LIST_DIR}/${GLEW_ARCHIVE_FILE}\"."
  )

  # Extract
  message(
    STATUS "Extracting \"${CMAKE_CURRENT_LIST_DIR}/${SDL_ARCHIVE_FILE}\"...")
  file(ARCHIVE_EXTRACT INPUT "${CMAKE_CURRENT_LIST_DIR}/${GLEW_ARCHIVE_FILE}"
       DESTINATION "${CMAKE_CURRENT_LIST_DIR}")
  message(
    STATUS
      "Extracted \"${CMAKE_CURRENT_LIST_DIR}/${GLEW_ARCHIVE_FILE}\" to \"${CMAKE_CURRENT_LIST_DIR}/${GLEW_EXTRACT_FOLDER}\"."
  )
  if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/${GLEW_ARCHIVE_FILE}")
    file(REMOVE "${CMAKE_CURRENT_LIST_DIR}/${GLEW_ARCHIVE_FILE}")
  endif()
endif()

set(GLM_VERSION 0.9.9.8)
set(GLM_DOWNLOAD_URI
    "https://github.com/g-truc/glm/releases/download/${GLM_VERSION}/glm-${GLM_VERSION}.zip"
)

set(GLM_ARCHIVE_FILE "glm-${GLM_VERSION}.zip")
set(GLM_EXTRACT_FOLDER "glm-${GLM_VERSION}")
if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/${GLM_EXTRACT_FOLDER}")

  # Downloading
  message(STATUS "Downloading GLM v${GLM_VERSION}...")
  file(DOWNLOAD "${GLM_DOWNLOAD_URI}"
       "${CMAKE_CURRENT_LIST_DIR}/${GLM_ARCHIVE_FILE}" SHOW_PROGRESS)
  message(
    STATUS
      "Downloaded \"${GLEW_ARCHIVE_FILE}\" to \"${CMAKE_CURRENT_LIST_DIR}/${GLEW_ARCHIVE_FILE}\"."
  )

  # Extract
  message(
    STATUS "Extracting \"${CMAKE_CURRENT_LIST_DIR}/${GLM_ARCHIVE_FILE}\"...")
  file(ARCHIVE_EXTRACT INPUT "${CMAKE_CURRENT_LIST_DIR}/${GLM_ARCHIVE_FILE}"
       DESTINATION "${CMAKE_CURRENT_LIST_DIR}")
  file(RENAME "${CMAKE_CURRENT_LIST_DIR}/glm"
       "${CMAKE_CURRENT_LIST_DIR}/${GLM_EXTRACT_FOLDER}" NO_REPLACE)
  message(
    STATUS
      "Extracted \"${CMAKE_CURRENT_LIST_DIR}/${GLM_ARCHIVE_FILE}\" to \"${CMAKE_CURRENT_LIST_DIR}/${GLM_EXTRACT_FOLDER}\"."
  )
  if(EXISTS "${CMAKE_CURRENT_LIST_DIR}/${GLM_ARCHIVE_FILE}")
    file(REMOVE "${CMAKE_CURRENT_LIST_DIR}/${GLM_ARCHIVE_FILE}")
  endif()
endif()
