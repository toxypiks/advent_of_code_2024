cmake_minimum_required(VERSION 3.16)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(LIST_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/list.c
  ${CMAKE_CURRENT_SOURCE_DIR}/include/list.h
  )

add_library(list)
target_sources(list
 PRIVATE
  ${LIST_SRC}
  )

set(TEST_LIST_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/test_list.c
  )

add_executable(test_list)
target_sources(test_list
 PRIVATE
  ${TEST_LIST_SRC}
  )
target_include_directories(test_list
 PUBLIC
  include
  )
target_link_libraries(test_list
  PUBLIC
  list
)

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

set(DAY_FOUR_2_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_four_2.c
  )

add_executable(day_four_2)
target_sources(day_four_2
 PRIVATE
 ${DAY_FOUR_2_SRC}
 )
set(DAY_FIVE_1_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/day_five_1.c
  )

add_executable(day_five_1)
target_sources(day_five_1
 PRIVATE
 ${DAY_FIVE_1_SRC}
 )
