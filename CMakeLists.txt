cmake_minimum_required(VERSION 3.25.0)
project(networking CXX)

find_package(Boost REQUIRED
        COMPONENTS
        system
        )

add_executable(networking src/networking.cc src/main.cc src/Peer.cc src/Peer.hpp)
target_link_libraries(networking
        Boost::system
)


install(TARGETS networking DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
