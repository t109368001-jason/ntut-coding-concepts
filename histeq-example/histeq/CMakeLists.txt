cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(histeq)

find_package(OpenCV 4.5.4 REQUIRED)

file(GLOB_RECURSE INCS include/*.h include/*.hpp)
file(GLOB_RECURSE SRCS src/*.cpp)

add_library(${PROJECT_NAME} ${INCS} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(
        ${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS})
