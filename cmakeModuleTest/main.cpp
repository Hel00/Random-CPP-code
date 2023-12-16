// https://www.kitware.com/import-cmake-the-experiment-is-over

#include <iostream>

import foo;
import bar;

int main()
{
  foo f;
  f.helloworld();
  std::cout << "Bar's ret int is: " << ret() << std::endl;
  return 0;
}
