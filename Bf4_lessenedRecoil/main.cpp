#include <cstdint>
#include <chrono>
#include <thread>
#include <array>
#include <windows.h>

using namespace std::chrono_literals;

template< size_t size = 0 >
uint64_t readMemory( const HANDLE &handle, const std::array<uint64_t, size> &address )
{
  uint64_t buffer = 0;
  static constexpr std::size_t bufferSize = 4;

  for ( const uint64_t &offset : address )
  {
    ReadProcessMemory( handle, (LPCVOID) (buffer + offset), &buffer, bufferSize, 0 );
  }

  return buffer;
}

void writeMemory( const HANDLE &handle, const uint64_t address, const uint64_t value )
{
  static constexpr size_t valueSize = 4;

  WriteProcessMemory( handle, (LPVOID) address, &value, valueSize, 0 );
}

int main()
{
  DWORD processId;
  static constexpr const char *processName = "Battlefield 4";
  static constexpr auto delay = 10s;

  HWND processHwnd = FindWindow(0, processName);
  GetWindowThreadProcessId(processHwnd, &processId);
  HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);

  static constexpr std::array addressList = {
    std::array< uint64_t, 3 > { 0x1423B2EC8ull, 0x128, 0x30 },
    std::array< uint64_t, 3 > { 0x1423B2EC8, 0x128, 0x30 },
    std::array< uint64_t, 3 > { 0x1423B2EC8, 0x128, 0x30 },
    std::array< uint64_t, 3 > { 0x1423B2EC8, 0x128, 0x30 },
  };

  while( true )
  {
    uint64_t sightRecoil = readMemory( processHandle, addressList[0] ) + 0x430;
    uint64_t sightSpread = readMemory( processHandle, addressList[1] ) + 0x434;

    uint64_t hipRecoil = readMemory( processHandle, addressList[2] ) + 0x438;
    uint64_t hipSpread = readMemory( processHandle, addressList[3] ) + 0x43C;

    writeMemory( processHandle, sightRecoil, 0x3F000000 );
    writeMemory( processHandle, sightSpread, 0x3F000000 );

    writeMemory( processHandle, hipRecoil, 0x3F000000 );
    writeMemory( processHandle, hipSpread, 0x3F000000 );

    std::this_thread::sleep_for( delay );
  }

  return 0;
}
