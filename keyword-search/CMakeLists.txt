cmake_minimum_required (VERSION 2.6)

project (KeywordSearch)

file (GLOB SEARCH_SOURCES
      "search/*.h"
      "search/*.cpp")
      
file (GLOB APP_SOURCES
      "app/*.h"
      "app/*.cpp")

set(INCLUDE_DIRS
  "search"
  "app"
  CACHE STRING "INCLUDES path" FORCE)

include_directories(
  ${INCLUDE_DIRS})


add_executable(keywordsearch ${APP_SOURCES} ${SEARCH_SOURCES})