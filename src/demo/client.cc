#include <boost/asio.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/address_v6.hpp>
#include <boost/asio/ip/resolver_base.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/socket_base.hpp>
#include <boost/system/detail/error_code.hpp>
#include <complex>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <system_error>
#include <vector>

#define DEBUG

using namespace boost;

static const auto &check_error = [](boost::system::error_code &error,
                                    std::string const &message = "") -> int {
  int error_value{};
  if (error.failed()) {
    std::cout << "Error! " << std::endl;
    std::cout << error.value() << error.message() << std::endl
              << message << std::endl;
    error_value = error.value();
  }
  error.clear();
  return error_value;
};

int main(int argc, char const *argv[]) {

  //  Get the host name from user
  if (argc < 3) {
    std::cout << "Specify the url for the host and port." << std::endl;
    return EXIT_FAILURE;
  }

  const std::string host_url = std::string{argv[1]};
  const std::string host_port = std::string{argv[2]};

#ifdef DEBUG
  { std::cout << host_url << std::endl; }
#endif

  asio::io_service ios{};
  system::error_code error{};
  // asio::ip::tcp::resolver::query resolver_query{
  //     host_url, host_port, boost::asio::ip::resolver_base::numeric_service};

  asio::ip::tcp::resolver resolver(ios);

  const auto dns_results = resolver.resolve(host_url, host_port, error);
  check_error(error);

  // const auto tcp = asio::ip::tcp::v6();
  auto tcpSocket = asio::ip::tcp::socket{ios};
  asio::connect(tcpSocket, dns_results, error);
  check_error(error);

  // std::vector<char> message{};
  // for (const auto item : "GET /index.html HTTP/1.1 \n\n") {
  //   message.push_back(item);
  // }
  // tcpSocket.send(message);
  // tcpSocket.wait(boost::asio::socket_base::wait_read);
  // message.clear();
  // tcpSocket.read_some(message);
  // std::cout << message.data() << std::endl;

  //   asio::ip::tcp::socket tcpSocket {}

  tcpSocket.close(error);
  check_error(error);

  return EXIT_SUCCESS;
}