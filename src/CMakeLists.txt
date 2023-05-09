# src

add_subdirectory("demo")

add_library(node Networking/networking.cc)

add_executable(main main.cc)
target_link_libraries(main
        Boost::system
        JsonCpp::JsonCpp
        oatpp::oatpp
)
#
#
#install(TARGETS main DESTINATION "."
#        RUNTIME DESTINATION bin
#        ARCHIVE DESTINATION lib
#        LIBRARY DESTINATION lib
#        )