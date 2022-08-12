#include <iostream>
#include <vector>
#include <string>
#include <climits>

template< typename T >
concept container = requires(T t)
{
  typename T::value_type;
  typename T::size_type;
  typename T::iterator;

  t.size();
  t.begin();
  t.end();
  t.cbegin();
  t.cend();
};

template < typename T >
constexpr auto numDigits( T number ) -> int
{
  int digits = 0;
  if  (number < 0 ) { digits = 1; }
  while ( number )
  {
    number /= 10;
    digits++;
  }

  return digits;
}

template< typename T >
requires container< T >
void logTable( T table )
{
  int const tableSize = table.size();
  int const tableDigitNum = numDigits( tableSize );
  static constinit int const maxDigit = numDigits( UINT_MAX );

  unsigned int index = 0;
  for ( const auto &item : table )
  {
    //std::cout << "Table at index " << index++ << " is " << item << '\n';

    std::cout << " ---------- \n"
              << '|';

    for ( int i = 0; i < (maxDigit - tableDigitNum) / 2; i++ )
    {
      std::cout << ' ';
    }

    std::cout << index;

    for ( int i = 0; i < (maxDigit - tableDigitNum) / 2; i++ )
    {
      std::cout << ' ';
    }

    std::cout << '|' << '\n';

    index++;
  }
  std::cout << " ---------- " << std::endl;

  std::cout << "Table size is " << tableSize << " and table digit number is " << tableDigitNum
            << "\n(maxDigit - tableDigitNum) / 2 = " << (maxDigit - tableDigitNum) / 2 << '\n'
            << " maxDigit - tableDigitNum      = " << maxDigit - tableDigitNum << std::endl;
}

auto main() -> int
{
  std::vector<char> arr{};

  for ( int i = 0; i <= 10; i++)
  {
    arr.push_back('A');
  }

  logTable(arr);

  /*for ( const uint8_t &i : arr )
  {
    std::cout << "I is " << (int)i << '\n';
  }*/

  return 0;
}

/*


 ----
| 124
 ----
*/
