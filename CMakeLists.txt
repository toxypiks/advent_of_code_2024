cmake_minimum_required(VERSION 3.16)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(DAY_ONE_1_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_one_1.c
  )

add_executable(day_one_1)
target_sources(day_one_1
 PRIVATE
  ${DAY_ONE_1_SRC}
  )

set(DAY_ONE_2_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_one_2.c
  )

add_executable(day_one_2)
target_sources(day_one_2
 PRIVATE
  ${DAY_ONE_2_SRC}
  )

set(DAY_TWO_1_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_two_1.c
  )

add_executable(day_two_1)
target_sources(day_two_1
 PRIVATE
  ${DAY_TWO_1_SRC}
  )

set(DAY_TWO_2_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_two_2.c
  )

add_executable(day_two_2)
target_sources(day_two_2
 PRIVATE
  ${DAY_TWO_2_SRC}
  )

set(DAY_THREE_1_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_three_1.c
  )

add_executable(day_three_1)
target_sources(day_three_1
 PRIVATE
  ${DAY_THREE_1_SRC}
  )

set(DAY_THREE_2_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_three_2.c
  )

add_executable(day_three_2)
target_sources(day_three_2
 PRIVATE
 ${DAY_THREE_2_SRC}
  )

set(DAY_FOUR_1_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_four_1.c
  )

add_executable(day_four_1)
target_sources(day_four_1
 PRIVATE
 ${DAY_FOUR_1_SRC}
  )
