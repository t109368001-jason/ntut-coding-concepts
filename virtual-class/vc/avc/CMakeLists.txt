cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(vc_avc)

file(GLOB_RECURSE INCS include/*.h include/*.hpp)
file(GLOB_RECURSE SRCS src/*.cpp)

add_library(${PROJECT_NAME} ${INCS} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)
