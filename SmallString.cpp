/* Compile with */
/* z++ -Oz -s main.cpp -c
   z++ -Oz -s main.o */

#include <cstdio>
#include <cstring>
#include <cstdlib>

class String
{
public:
  const char *data;
  std::size_t length;

  String( const char *data )
  {
    this->length = strlen( data );

    this->data = (const char*) std::malloc( sizeof(const char*) * this->length );

    std::memmove( (char*) this->data, data, this->length );
  }

  void operator+=( const char *data )
  {
    std::size_t resultLength = strlen( data );
    char result[ this->length + resultLength ];

    std::strcat( result, this->data );
    std::strcat( result, data );

    this->data = (const char*) std::realloc( (void*) this->data, sizeof(const char*) + this->length + resultLength );

    std::strcpy( (char*) this->data, result );
  }
};

int main()
{
  String str = "Hey";
  str = "Hello";
  str += " World!";

  printf("String is %s\n", str.data);
}
