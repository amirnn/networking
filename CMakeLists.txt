cmake_minimum_required(VERSION 3.25.0)
project(networking CXX)


add_executable(networking src/networking.cc src/main.cc src/Peer.cc src/Peer.hpp)



install(TARGETS networking DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
