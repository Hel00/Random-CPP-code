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
