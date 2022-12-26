cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(hevc-parser)

file(GLOB_RECURSE INCS include/*.h include/*.hpp)
file(GLOB_RECURSE SRCS src/*.cpp)

add_library(${PROJECT_NAME} STATIC ${INCS} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE src)

target_link_libraries(${PROJECT_NAME} PRIVATE vc_hevc virtual-encoder)