/* https://stackoverflow.com/a/11622727 */

// clang++ --std=c++23 main.cpp -Wl,--format=binary -Wl,data -Wl,--format=default

#include <cstdint>
#include <cstdio>

extern uint8_t data[]     asm("_binary_data_start");
extern uint8_t data_end[] asm("_binary_data_end");

int main()
{
  for (uint8_t *ptr = data; ptr < data_end; ptr++)
  {
    printf("%c\n", *ptr);
  }
}
