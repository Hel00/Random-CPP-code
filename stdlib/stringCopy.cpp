constexpr void stringCopy(char *destination, char *source)
{
  while ( (*destination++ = *source++) != '\0');
}

/* USE CASE */

#include <iostream>

int main()
{
  char source[] = "Hello";
  char destination[5];

  stringCopy(destination, source);

  std::cout << destination << std::endl;
}
