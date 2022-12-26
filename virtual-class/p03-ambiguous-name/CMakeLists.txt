cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(p03-ambiguous-name)

add_subdirectory(parser/virtual-encoder)
add_subdirectory(parser/avc-parser)
add_subdirectory(parser/hevc-parser)
add_subdirectory(parser/vvc-parser)

file(GLOB_RECURSE INCS include/*.h include/*.hpp)
file(GLOB_RECURSE SRCS src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${INCS} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PRIVATE virtual-encoder avc-parser hevc-parser vvc-parser)