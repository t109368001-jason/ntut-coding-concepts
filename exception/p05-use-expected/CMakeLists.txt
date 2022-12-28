cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(p05-use-expected)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
