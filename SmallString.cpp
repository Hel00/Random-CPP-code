/* Compile with */

/* z++ -Oz -s main.cpp -c
   z++ -Oz -s main.o */

#include <cstdlib>
#include <cstring>
#include <cstdio>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define STRSIZE 10

class String
{
public:
  char       *data;
  std::size_t size;

  String( char *data )
  {
    this->size = MAX( std::strlen( data ) + 1, STRSIZE );
    this->data = (char*) std::malloc( this->size );

    std::strcpy( this->data, data );
  }

  void free()
  {
    std::free( this->data );
    std::free( this );
  }

  void grow( std::size_t newSize )
  {
    if ( newSize <= this->size ) { return; }

    std::size_t oldSize = this->size;

    while ( this->size < newSize ) { this->size *=2; }

    this->data = (char*) std::realloc( (void*) this->data, this->size );

    std::memset( (void*)(this->data + oldSize), '\0', this->size - oldSize );
  }

  void grow()
  {
    this->grow( this->size * 2 );
  }

  void shrink()
  {
    this->size /= 2;
    this->size = MAX( this->size, STRSIZE );

    this->data = (char*) std::realloc( (void*) this->data, this->size );

    this->data[ this->size - 1 ] = '\0';
  }

  void append( char *data )
  {
    std::size_t length = std::strlen( this->data );

    this->grow( this->size + length );

    for ( int i = 0; i < std::strlen(data); i++ ) { this->data[ length + i ] = data[ i ]; }
  }

  void append( char data )
  {
    std::size_t length = std::strlen( this->data );

    if ( length >= this->size - 1 ) { this->grow(); }

    this->data[ length ] = data;
  }

  char *get()
  {
    return this->data;
  }

  char getChar( std::size_t index )
  {
    if ( index >= this->size ) { return '\0'; }

    return this->data[ index ];
  }

  std::size_t getSize()   { return this->size; }
  std::size_t getLength() { return std::strlen( this->data ); }

  void set( char *data )
  {
    this->grow( this->size + std::strlen( data ) );
    std::strcpy( this->data, data );
  }

};


int main()
{
  String string = "Hey";

  string.grow();
  string.set("Hello");

  string.grow();
  string.append(" World!!");

  printf("String is: %s", string.get());

  return 0;
}
