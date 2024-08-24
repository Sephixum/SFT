cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

project(software_ray_tracing VERSION 0.0.1 DESCRIPTION "A project based of the the ray tracing in one weekend series of books." LANGUAGES CXX)

add_executable(output)
target_sources(output PRIVATE src/main.cxx)
target_include_directories(output PRIVATE {CMAKE_CURRENT_SOURCE_DIR}/src/)