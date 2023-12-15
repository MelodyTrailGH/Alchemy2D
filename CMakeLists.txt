cmake_minimum_required(VERSION 3.1.9...3.5.0)
project(
  Alchemy2D
  VERSION 1.0.0.0
  DESCRIPTION ""
  HOMEPAGE_URL ""
  LANGUAGES C CXX)

set(ALCHEMY_DEPENDENCIES_DIR
    "${CMAKE_CURRENT_LIST_DIR}/Dependencies/Third-Party/")

include(${ALCHEMY_DEPENDENCIES_DIR}/BuildDependencies.cmake)
