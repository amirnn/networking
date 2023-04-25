find_package(Boost REQUIRED COMPONENTS system)
message(STATUS "Boost is here: " ${Boost_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

find_package(JsonCpp REQUIRED)
message(STATUS "JsonCpp is here: " ${JsonCpp_INCLUDE_DIRS})
include_directories(${JsonCpp_INCLUDE_DIRS})

find_package(oatpp REQUIRED)
message(STATUS "oatpp is here: " ${oatpp_INCLUDE_DIRS})
include_directories(${oatpp_INCLUDE_DIRS})