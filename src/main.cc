#include "Networking/networking.hpp"
#include <boost/asio.hpp>
#include <json/json.h>
#include <chrono>
#include <iostream>

using namespace boost;

int main() {
  const auto print = [&](const  std::error_code&){
	  std::cout << "Hello, world! from io" << std::endl;
  };
  asio::io_context io;
  asio::steady_timer t(io, std::chrono::seconds(5));
  t.async_wait(print);
  io.run();

  std::cout << "Hello, world!" << std::endl;
  return  EXIT_SUCCESS;
}
