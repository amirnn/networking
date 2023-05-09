#pragma once

#include <boost/asio.hpp>


namespace bluecpp {

class node {
  using Address = boost::asio::ip::address;

  explicit node(const Address& ) noexcept;
  [[nodiscard]] auto getAddress() const noexcept -> Address {return m_getAddress();};

private:
  Address address{};
  [[nodiscard]] virtual auto m_getAddress() const noexcept -> Address = 0;

};


}

