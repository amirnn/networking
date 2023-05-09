# src/demo

add_executable(client client.cc)
target_link_libraries(client Boost::system)

add_executable(host host.cc)
target_link_libraries(host Boost::system)