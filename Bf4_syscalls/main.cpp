// zig build-exe -target x86_64-windows-none -L"/home/hel/.wine/drive_c/windows/system32/" -dynamic -lkernel32 -luser32 -cflags --std=c++20 -- --subsystem windows -fentry=Main -O ReleaseSmall -fstrip -flto --gc-sections -ffunction-sections main.cpp

// z++ -Oz -s main.cpp --target=x86_64-windows-gnu -L"/home/hel/.wine/drive_c/windows/system32/" -dynamic -lkernel32 -luser32 -o main.exe

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

  static constexpr auto QBB_PATH = "Gameplay/Weapons/QBB95/QBB95";
  static constexpr auto QBB_PATH_SIZE = __builtin_strlen(QBB_PATH) + 1;
  static constexpr auto QBB_ROF = 0x442f0000;
  
  DWORD processId;
  HWND processHwnd = FindWindowA(0, processName);
  GetWindowThreadProcessId(processHwnd, &processId);
  HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, false, processId);

  uint64_t unlockEverything;

  static constexpr array<uint64_t, 2> swayLocation{0x1423B2EC8ull, 0x128ull};
  uint64_t swayBase;
  uint64_t sightRecoil;
  uint64_t sightSpread;
  uint64_t hipRecoil;
  uint64_t hipSpread;

  static constexpr array<uint64_t, 4> weaponNameLocation{0x1423B2EC8ull, 0x138ull, 0x1D0ull, 0x10ull};
  static constexpr array<uint64_t, 3> qbbRofLocation{0x1423B2EC8ull, 0x128ull, 0x10ull};

  while( true )
  {
    unlockEverything = readMemory( processHandle, 0x1423717C0 ) + 0x54;
    writeMemory( processHandle, unlockEverything, 1 );

    swayBase = readMemory(processHandle, swayLocation) + 0x30ull;

    sightRecoil = readMemory(processHandle, swayBase) + 0x430;
    sightSpread = readMemory(processHandle, swayBase) + 0x434;
    hipRecoil = readMemory(processHandle, swayBase) + 0x438;
    hipSpread = readMemory(processHandle, swayBase) + 0x43C;

    auto weaponNameAddress = readMemory(processHandle, weaponNameLocation) + 0x00;
    auto weaponName = readString<QBB_PATH_SIZE>(processHandle, weaponNameAddress);

    writeMemory( processHandle, sightRecoil, recoil );
    writeMemory( processHandle, sightSpread, recoil );

    writeMemory( processHandle, hipRecoil, recoil );
    writeMemory( processHandle, hipSpread, recoil );
    
    if (!__builtin_strcmp(QBB_PATH, weaponName.data))
    {
      uint64_t qbbRof = readMemory(processHandle, qbbRofLocation) + 0x1C8ull;

      writeMemory(processHandle,
                  qbbRof,
                  0x442f0000);
    }

    Sleep(delay);
  }
}

extern "C" void wWinMainCRTStartup() { Main(); }
extern "C" void _fltused() {}
