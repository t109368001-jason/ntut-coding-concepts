cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(virtual-class)

add_subdirectory(vc/avc)
add_subdirectory(vc/hevc)
add_subdirectory(vc/vvc)

add_subdirectory(p01-without-virtual-class)
add_subdirectory(p02-use-virtual-class)
