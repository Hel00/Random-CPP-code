#include <iostream>

using std::cout;
using std::endl;

struct Type
{
protected:
  using Int = int;
};

struct Module : public Type
{
public:
  Int data;
};

int main()
{
  Module module { .data = 1 };

  // Module::INT typeTest = 1; // Error

  cout << module.data << endl;
}
