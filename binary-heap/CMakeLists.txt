cmake_minimum_required (VERSION 2.6)

project (BinaryHeap)

file (GLOB HEAP_SOURCES
      "src/*.h"
      "src/*.cpp")
      
file (GLOB APP_SOURCES
      "app/*.h"
      "app/*.cpp")

set(INCLUDE_DIRS
  "src"
  "app"
  CACHE STRING "INCLUDES path" FORCE)

include_directories(
  ${INCLUDE_DIRS})


add_executable(binaryheapTest ${APP_SOURCES} ${HEAP_SOURCES})