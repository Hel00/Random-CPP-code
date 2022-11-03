// UNFINISHED

#include <iostream>

using std::cout;
using std::endl;

enum  OptionType { Some = 0, None };

template<typename T>
struct Option
{
    OptionType type = None;
    union
    {
        struct { T value; }; // Some
        struct {};           // None
    };

    Option( T value )
    {
      this->type = Some;
      this->value = value;
    }

    Option() = default;
};

int main()
{
  Option<void*> option;
  Option optionSome(42);
}

// Kinda implemented

#include <iostream>

using std::cout;
using std::endl;

template< typename T >
struct Option
{
  T value;
};

template<>
struct Option<void*>
{
};

int main()
{
  Option<int> o1{2};
  Option<float> o2{2.42};
  Option<void*> o3{};

  cout << "Option `int` is " << o1.value << endl;
  cout << "Option `float` is " << o2.value << endl;
  //cout << "option `void*` is " << o3.value << endl;
}
