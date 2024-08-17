// zig build-exe -target x86_64-windows-none -L"/home/hel/.wine/drive_c/windows/system32/" -dynamic -lkernel32 -luser32 -cflags --std=c++20 -- --subsystem windows -fentry=Main -O ReleaseSmall -fstrip -flto --gc-sections -ffunction-sections main.cpp

#include "types.hpp"
#include "win32Utils.hpp"
#include "memory.hpp"

// 0.5 = 0x3F000000
// 0.75 = 0x3F400000
// 0.85 = 0x3F59999A

extern "C" void Main()
{
  static constexpr const char *processName = "Battlefield 4";
  static constexpr auto PROCESS_ALL_ACCESS = (0x000F0000L | 0x00100000L | 0xFFF); // 2035711
  static constexpr auto delay = 10'000;
  static constexpr auto recoil = 0x3F000000;

  DWORD processId;
  HWND processHwnd = FindWindowA(0, processName);
  GetWindowThreadProcessId(processHwnd, &processId);
  HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);

  static constexpr array< uint64_t, 3 > lessenedRecoil = { 0x1423B2EC8ull, 0x128ull, 0x30ull };

  uint64_t unlockEverything;

  uint64_t sightRecoil;
  uint64_t sightSpread;
  uint64_t hipRecoil;
  uint64_t hipSpread;

  while( true )
  {
    unlockEverything = readMemory( processHandle, 0x1423717C0 ) + 0X54;
    writeMemory( processHandle, unlockEverything, 1 );

    sightRecoil = readMemory( processHandle, lessenedRecoil ) + 0x430;
    sightSpread = readMemory( processHandle, lessenedRecoil ) + 0x434;

    hipRecoil = readMemory( processHandle, lessenedRecoil ) + 0x438;
    hipSpread = readMemory( processHandle, lessenedRecoil ) + 0x43C;

    writeMemory( processHandle, sightRecoil, recoil );
    writeMemory( processHandle, sightSpread, recoil );

    writeMemory( processHandle, hipRecoil, recoil );
    writeMemory( processHandle, hipSpread, recoil );

    Sleep(delay);
  }
}

extern "C" void wWinMainCRTStartup() { Main(); }
