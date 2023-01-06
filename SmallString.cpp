#include <cstdio>
#include <cstdlib>
#include <cstring>

constexpr auto MAX( std::size_t a, char b ) -> std::size_t
{
  return ((a) > (b) ? (a) : (b));
}
static constinit char const STRSIZE = 10;

class String
{
  char       *data;
  std::size_t size;

public:
  explicit String( const char *data ) : size( MAX( std::strlen( data ) + 1, STRSIZE ) )
  {
    this->data = static_cast< char* >( std::malloc( this->size ) );

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

    this->data = static_cast< char* >( std::realloc(
                                       static_cast< void* >( this->data ),
                                       this->size ) );

    std::memset( static_cast< void* >( this->data + oldSize ), '\0', this->size - oldSize );
  }

  void grow()
  {
    this->grow( this->size * 2 );
  }

  void shrink()
  {
    this->size /= 2;
    this->size = MAX( this->size, STRSIZE );

    this->data = static_cast< char* >( std::realloc( static_cast< void* >( this->data ), this->size ) );

    this->data[ this->size - 1 ] = '\0';
  }

  void append( const char *data )
  {
    std::size_t length = std::strlen( this->data );

    this->grow( this->size + length );

    for ( std::size_t i = 0; i < std::strlen(data); i++ ) { this->data[ length + i ] = data[ i ]; }
  }

  void append( char data )
  {
    std::size_t length = std::strlen( this->data );

    if ( length >= this->size - 1 ) { this->grow(); }

    this->data[ length ] = data;
  }

  auto get() -> char*
  {
    return this->data;
  }

  auto getChar( std::size_t index ) -> char
  {
    if ( index >= this->size ) { return '\0'; }

    return this->data[ index ];
  }

  auto getSize()   -> std::size_t {        return this->size;         }
  auto getLength() -> std::size_t { return std::strlen( this->data ); }

  void set( const char *data )
  {
    this->grow( this->size + std::strlen( data ) );
    std::strcpy( this->data, data );
  }

};

auto main() -> int
{
  String string("Hey");

  string.grow();
  string.set("Hello");

  string.grow();
  string.append(" World!!");

  printf("String is: %s", string.get());

  return 0;
}
