#include <iostream>

using std::cout;
using std::endl;

union RustLikeEnum
{
  using KeyInput = uint64_t;
  using UserInput = std::string_view;
};

int main()
{
  auto rle = RustLikeEnum::KeyInput( 65 );
  //auto rle = RustLikeEnum::UserInput( "Hello" );

  cout << "Rust like enum example " << rle << endl;
}
