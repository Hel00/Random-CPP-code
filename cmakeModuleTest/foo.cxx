module;
#include <iostream>

// first thing after the Global module fragment must be a module command
export module foo;

export class foo
{
public:
  foo();
  ~foo();
  void helloworld();
};

foo::foo() = default;
foo::~foo() = default;
void foo::helloworld() { std::cout << "Hello, World!" << std::endl ; }
