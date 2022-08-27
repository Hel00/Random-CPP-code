#include <cstdio>

auto operator ""_print(unsigned long long data) -> long long
{
  printf("Data is: %d\n", data);

  return static_cast<long long>(data);
}

auto main() -> int
{
  int x = 42_print;
}
