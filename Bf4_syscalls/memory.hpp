#pragma once

#include "types.hpp"
#include "win32Utils.hpp"

template<SIZE_T SIZE = 0>
uint64_t readMemory(const HANDLE &handle, const array<uint64_t, SIZE> &address)
{
  uint64_t buffer = 0;
  static constexpr SIZE_T bufferSize = 4;

  for (const uint64_t &offset : address)
  {
    ReadProcessMemory(handle, (LPCVOID) (buffer + offset), &buffer, bufferSize, 0);
  }

  return buffer;
}

uint64_t readMemory(const HANDLE &handle, const uint64_t address)
{
  uint64_t buffer = 0;
  static constexpr SIZE_T bufferSize = 4;

  ReadProcessMemory(handle, (LPCVOID) (buffer + address), &buffer, bufferSize, 0);

  return buffer;
}

void writeMemory(const HANDLE &handle, const uint64_t address, const uint64_t value)
{
  static constexpr SIZE_T valueSize = 4;

  WriteProcessMemory( handle, (LPVOID) address, &value, valueSize, 0);
}

template<__SIZE_TYPE__ SIZE>
auto readString(const HANDLE &handle, const uint64_t address)
{
  struct Result
  {
    char data[SIZE]{};
    __SIZE_TYPE__ size = SIZE;
  };

  char buffer[SIZE]{};

  ReadProcessMemory(handle, (LPVOID) address, &buffer, SIZE, 0);

  Result result;

  for (__SIZE_TYPE__ index = 0; index <= SIZE; index++)
  {
    result.data[index] = buffer[index];
  }

  return result;
}
