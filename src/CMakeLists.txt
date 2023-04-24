# src

add_executable(main Networking/networking.cc Peer/Peer.cc main.cc)
target_link_libraries(main
        Boost::system
        # nlohmann_json::nlohmann_json
        jsoncpp::jsoncpp
        oatpp::oatpp
)


install(TARGETS main DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )