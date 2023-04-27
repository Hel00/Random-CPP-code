#include <iostream>

template<int N>
constexpr char const (&getCharArray())[N]
{
  static char const value[N] = "Hello, World!";
  return value;
}

int main()
{
  // Use the getCharArray function to generate a const char array
  const char (&array)[14] = getCharArray<14>();
  std::cout << array << std::endl;
  return 0;
}
