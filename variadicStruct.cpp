#include <iostream>

using std::cout;
using std::endl;

union PersonType
{

  struct Person
  {
    std::string name;
    uint8_t age;
  };

  struct Student
  {
    uint64_t id;
    uint8_t age;
  };

};

int main()
{
  auto person = PersonType::Person{ "Hel", 24 };

  cout << person.name << endl;
}
