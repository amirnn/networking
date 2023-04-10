cmake_minimum_required(VERSION 3.15)
project(networking CXX)



add_executable(networking src/networking.cpp src/main.cpp)



install(TARGETS networking DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
