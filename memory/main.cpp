#include "memory.h"

#include <array>
#include <cstdint>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main()
{
  Memory::initializeTarget("Battlefield 4");


  const auto delay = 2.5s;
  const float halfGunSway = 0.5;

  constexpr std::array< uint64_t, 4 > sightRecoilPointer { 0x1423B2EC8, 0x128, 0x30, 0x430 };
  constexpr std::array< uint64_t, 4 > sightSpreadPointer { 0x1423B2EC8, 0x128, 0x30, 0x434 };
  constexpr std::array< uint64_t, 4 > hipRecoilPointer   { 0x1423B2EC8, 0x128, 0x30, 0x438 };
  constexpr std::array< uint64_t, 4 > hipSpreadPointer   { 0x1423B2EC8, 0x128, 0x30, 0x43C };


  Memory sightRecoil ( sightRecoilPointer );
  Memory sightSpread ( sightSpreadPointer );
  Memory hipRecoil   (  hipRecoilPointer  );
  Memory hipSpread   (  hipSpreadPointer  );

  while ( true )
  {
    sightRecoil = Memory ( sightRecoilPointer );
    sightSpread = Memory ( sightSpreadPointer );
    hipRecoil   = Memory (  hipRecoilPointer  );
    hipSpread   = Memory (  hipSpreadPointer  );

    sightRecoil.write ( halfGunSway );
    sightSpread.write ( halfGunSway );
    hipRecoil.write   ( halfGunSway );
    hipSpread.write   ( halfGunSway );

    std::this_thread::sleep_for( delay );
  }

  return 0;
}
