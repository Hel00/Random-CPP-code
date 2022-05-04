#include <array>
#include <cstdio>

template <typename T, int from, int to>
consteval auto genRange() -> std::array<T, to - from>
{
  std::array<T, to - from> data{};
  int index = {from};

  for (T &val : data)
  {
    if (index == to) { break; }

    val = index++;
  }

  return data;
}

auto main() -> int
{
  const char from = 'A',
             to   = 'Z';

  std::array<char, to - from> alphabet = genRange<char, from, to>();

  for (char &letter : alphabet)
  {
    printf("Letter: %c\n", letter);
  }

  return 0;
}
