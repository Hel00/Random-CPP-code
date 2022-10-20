#include "memory.h"

#include <iostream>
#include <array>
#include <cstdint>

using std::cout;
using std::endl;

int main()
{
  cout << "Hello World!" << endl;

  Memory::initializeTarget("Battlefield 4");

  Memory test( std::array<uint64_t, 4>{ 0x1423B2EC8, 0x128, 0x30, 0x430 } );

  test.write(0.5f);

  cout << "Address is " << test.getAddress() << '\n';

  return 0;
}

/*
let sight_recoil = read_memory(handle, [0x1423B2EC8, 0x128, 0x30, ]) + 0x430;
let sight_spread = read_memory(handle, [0x1423B2EC8, 0x128, 0x30, ]) + 0x434;

let hip_recoil = read_memory(handle, [0x1423B2EC8, 0x128, 0x30, ]) + 0x438;
let hip_spread = read_memory(handle, [0x1423B2EC8, 0x128, 0x30, ]) + 0x43C;
*/
