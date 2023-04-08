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
  consteval auto replaceAndFill() const
  {
    FixedString<stream.size + 10> temp{};

    for (int index = 0; index <= stream.size; index++)
    {
      temp[index] = stream[index];
    }

    for (int index = stream.size; index < stream.size + 10; index++)
    {
      temp[index] = 'A';
    }

    return temp;
  }
};

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  static constexpr FixedStringManager<"Heya!"> fixedStringManager{};

  static constexpr auto invertedStream = fixedStringManager.Invert();

  cout << "Inverted `FixedString` is: " << invertedStream << endl;

  static constexpr auto replaced = fixedStringManager.replaceAndFill();

  cout << "Replaced and filled `FixedString` is: " << replaced << endl;
}
