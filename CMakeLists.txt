cmake_minimum_required(VERSION 3.25.0)
project(networking CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include("conan/Dependencies.cmake")

add_subdirectory("src")

