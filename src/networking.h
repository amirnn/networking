#pragma once


#ifdef _WIN32
  #define NETWORKING_EXPORT __declspec(dllexport)
#else
  #define NETWORKING_EXPORT
#endif

NETWORKING_EXPORT void networking();
