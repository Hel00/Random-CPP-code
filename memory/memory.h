#pragma once

#include <Windows.h>
#include <cstdint>
#include <array>

class Memory
{
  static HANDLE handle;
  uint64_t address;

public:
  Memory( uint64_t address );

  template< size_t size >
  Memory( std::array<uint64_t, size> pointers );

  uint64_t getAddress() { return this->address; }

  template< typename T >
  T read();
  template< typename T >
  void write(T);

  static void initializeTarget(const char *target);
};


// IMPLEMENTATION


HANDLE Memory::handle{};

void Memory::initializeTarget(const char *target)
{
  DWORD processId = 0;
  HWND hwnd = FindWindowA( 0, target );
  GetWindowThreadProcessId( hwnd, &processId );

  Memory::handle = OpenProcess( PROCESS_ALL_ACCESS, 0, processId );
}

Memory::Memory( uint64_t address ) : address( address ) {}

template< size_t size >
Memory::Memory( std::array<uint64_t, size> pointers )
{
  uint64_t buffer = 0;
  constexpr uint64_t bufferSize = sizeof(buffer);
  const uint64_t pointersSize = pointers.size();
  const uint64_t lastPointer = pointers[ pointersSize - 1 ];


  for ( int index = 0; const uint64_t &pointer : pointers )
  {
    if ( index++ == pointersSize - 1 )
    {
      buffer += lastPointer;
      break;
    }

    ReadProcessMemory
    (
      Memory::handle,
      (LPCVOID) (buffer + pointer),
      &buffer,
      bufferSize,
      0
    );

  }

  this->address = buffer;
}

template< typename T >
T Memory::read()
{
  T result = 0;

  ReadProcessMemory( Memory::handle, (LPCVOID) this->address, (LPVOID) &result, sizeof(result), 0 );

  return result;
}

template< typename T >
void Memory::write( T value )
{
  WriteProcessMemory( Memory::handle, (LPVOID) this->address, &value, sizeof(value), 0 );
}
