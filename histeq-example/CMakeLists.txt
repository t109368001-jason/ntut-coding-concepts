cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(histeq-example)

find_package(OpenCV 4.5.4 REQUIRED)

add_subdirectory(histeq)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        ${OpenCV_LIBS}
        histeq
)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/lena_gray.bmp
        ${CMAKE_CURRENT_BINARY_DIR}/lena_gray.bmp
)
