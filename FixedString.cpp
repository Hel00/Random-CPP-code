template<unsigned SIZE>
struct FixedString
{
  int size = SIZE;
  char buffer[SIZE + 1]{};

  consteval FixedString(char const *stream)
  {
    for (unsigned index = 0; index != SIZE; ++index) { buffer[index] = stream[index]; }
  }

  consteval operator char const*() const { return buffer; }
};

template<unsigned N>
FixedString(char const (&)[N]) -> FixedString<N - 1>;

template<FixedString stream>
class FixedStringManager
{
public:
  FixedString<stream.size>
  consteval Invert() const
  {
    FixedString<stream.size> inverted_string(stream.buffer);

    for (unsigned index = 0; index < stream.size / 2; ++index)
    {
      char temp = inverted_string.buffer[index];
      inverted_string.buffer[index] = inverted_string.buffer[stream.size - index - 1];
      inverted_string.buffer[stream.size - index - 1] = temp;
    }

    return inverted_string;
  }
};

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  static constexpr FixedStringManager<"Heya!"> fixedStringManager{};

  static constexpr auto invertedStream = fixedStringManager.Invert();

  cout << "Thing is: " << invertedStream << endl;
}
