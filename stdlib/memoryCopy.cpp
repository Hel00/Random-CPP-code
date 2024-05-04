template<typename T>
constexpr void memoryCopy(T *destination, T *source, unsigned long long length)
{
  while (length-- > 0) { *destination++ = *source++; }
}

/* USE CASE */

consteval int test()
{
  int x[] = {1, 2, 3, 4};
  int y[4];

  memoryCopy<int>(y, x, 4);

  return y[3];
}

#include <iostream>

int main()
{
  std::cout << test() << std::endl;
}
