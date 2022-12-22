cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(p01-without-virtual-class)

add_subdirectory(vc/avc)
add_subdirectory(vc/hevc)
add_subdirectory(vc/vvc)

file(GLOB_RECURSE INCS include/*.h include/*.hpp)
file(GLOB_RECURSE SRCS src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${INCS} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} PRIVATE avc hevc vvc)