#include <iostream>
#include <iomanip>
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
  static constinit int const maxDigit = numDigits( UINT_MAX );

  unsigned int index = 0;
  for ( const auto &item : table )
  {
    std::cout << " ----------      ------------------------------\n"
              << '|';

    std::cout << std::setw( maxDigit ) << index;/* << ' ' << tableDigitNum;*/

    std::cout << "| -> |" << std::setw( maxDigit * 3 ) <<item << '|' << '\n';

    index++;
  }
  std::cout << " ----------      ------------------------------ " << std::endl;
}

auto main() -> int
{
  std::vector<std::string> arr{};

  for ( int i = 0; i <= 100; i++)
  {
    arr.push_back("Hello!");
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
