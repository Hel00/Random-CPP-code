/* https://stackoverflow.com/a/11622727 */

// clang++ --std=c++23 main.cpp -Wl,--format=binary -Wl,data -Wl,--format=default

#include <cstdint>
#include <cstdio>

extern uint8_t data[]     asm("_binary_data_start");
extern uint8_t data_end[] asm("_binary_data_end");

int main()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%c\n", data[i]);
    }
}

