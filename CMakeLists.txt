cmake_minimum_required(VERSION 3.25.0)
project(networking CXX)

find_package(Boost REQUIRED
        COMPONENTS
        system
        )
# find_package(nlohmann_json REQUIRED)
find_package(jsoncpp REQUIRED)
find_package(oatpp REQUIRED)

add_executable(networking src/networking.cc src/main.cc src/Peer.cc src/Peer.hpp)
target_link_libraries(networking
        Boost::system
        # nlohmann_json::nlohmann_json
        jsoncpp::jsoncpp
        oatpp::oatpp
)


install(TARGETS networking DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
