cmake_minimum_required(VERSION 3.10)
project(Delta)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(delta ${SOURCES})

target_link_libraries(delta)

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(delta PUBLIC ${MATH_LIBRARY})
endif()