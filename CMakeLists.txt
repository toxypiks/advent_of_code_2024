cmake_minimum_required(VERSION 3.16)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(DAY_ONE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_one.c
  )

add_executable(day_one)
target_sources(day_one
 PRIVATE
  ${DAY_ONE}
  )
