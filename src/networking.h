#pragma once


#ifdef _WIN32
  #define NETWORKING_EXPORT __declspec(dllexport)
#else
  #define NETWORKING_EXPORT
#endif

namespace bluecpp {

    NETWORKING_EXPORT void getInfo() noexcept;
}

