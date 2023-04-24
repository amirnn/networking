cmake_minimum_required(VERSION 3.25.0)
project(networking CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

find_package(Boost REQUIRED
        COMPONENTS
        system
        )
# find_package(nlohmann_json REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(oatpp REQUIRED)

add_subdirectory("src")

