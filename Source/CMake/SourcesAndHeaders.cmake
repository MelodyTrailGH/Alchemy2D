file(GLOB_RECURSE ALCHEMY_SOURCES 
    "${ALCHEMY_SOURCE_DIRECTORY}/Core/Math/Vector2.cc"
    #"${ALCHEMY_SOURCE_DIRECTORY}/Graphics/Window.cc"
    "${ALCHEMY_SOURCE_DIRECTORY}/Graphics/Renderer.cc"
    "${ALCHEMY_SOURCE_DIRECTORY}/Graphics/WindowManager.cc"
    "${ALCHEMY_SOURCE_DIRECTORY}/Core/Application.cc"

)

file(GLOB_RECURSE ALCHEMY_PUBLIC_HEADERS 
    "${ALCHEMY_INCLUDE_DIRECTORY}/Alchemy2D/Core/Math/Vector2.hh"
    "${ALCHEMY_INCLUDE_DIRECTORY}/Alchemy2D/Core/Math/Math.hh"
    "${ALCHEMY_INCLUDE_DIRECTORY}/Alchemy2D/Graphics/Window.hh"
    "${ALCHEMY_INCLUDE_DIRECTORY}/Alchemy2D/Graphics/WindowEvent.hh"
    "${ALCHEMY_INCLUDE_DIRECTORY}/Alchemy2D/Graphics/WindowFlag.hh"
    "${ALCHEMY_INCLUDE_DIRECTORY}/Alchemy2D/Graphics/Renderer.hh"
    "${ALCHEMY_INCLUDE_DIRECTORY}/Alchemy2D/Graphics/WindowManager.hh"
    "${ALCHEMY_INCLUDE_DIRECTORY}/Alchemy2D/Core/Application.hh"
    #"${ALCHEMY_INCLUDE_DIRECTORY}/Alchemy2D/"
)

# Applying the source files.
target_sources(${ALCHEMY_TARGET_NAME} PRIVATE ${ALCHEMY_SOURCES}
                                              ${ALCHEMY_PUBLIC_HEADERS})

target_include_directories(
  ${ALCHEMY_TARGET_NAME}
  PUBLIC $<BUILD_INTERFACE:${ALCHEMY_INCLUDE_DIRECTORY}>
         $<INSTALL_INTERFACE:include/${ALCHEMY_LIBRARY_NAME}>)
