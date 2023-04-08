template<unsigned SIZE>
struct FixedString
{
  int size = SIZE;
  char buffer[SIZE + 1]{};

  consteval FixedString(char const *stream)
  {
    for (unsigned index = 0; index != SIZE; ++index) { buffer[index] = stream[index]; }
  }

  consteval FixedString()
  {
    for (unsigned index = 0; index != SIZE; ++index) { buffer[index] = '\0'; }
  }

  consteval operator char const*() const { return buffer; }

  consteval char &operator[](unsigned index)
  {
    return this->buffer[index];
  }
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

template<FixedString stream>
consteval auto replaceAndFill()
{
  FixedString<stream.size + 10> temp{};

  for (int i = 0; i <= stream.size; i++)
  {
    temp[i] = stream[i];
  }

  for (int i = stream.size; i < stream.size + 10; i++)
  {
    temp[i] = 'A';
  }

  return temp;
}

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  static constexpr FixedStringManager<"Heya!"> fixedStringManager{};

  static constexpr auto invertedStream = fixedStringManager.Invert();

  cout << "Inverted `FixedString` is: " << invertedStream << endl;

  static constexpr auto replaced = replaceAndFill<invertedStream>();

  cout << "Replaced and filled `FixedString` is: " << replaced << endl;
}
