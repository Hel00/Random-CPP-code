#include <cstdio>
#include <cstdlib>
#include <cstring>

constexpr inline auto MAX( std::size_t a, char b ) -> std::size_t
{
  return ((a) > (b) ? (a) : (b));
}

constinit char const STRSIZE = 10;

class String
{
  char       *m_data;
  std::size_t m_size;

public:
  explicit String( const char *data ) : m_size( MAX( std::strlen( data ) + 1, STRSIZE ) )
  {
    this->m_data = static_cast< char* >( std::malloc( this->m_size ) );

    std::strcpy( this->m_data, m_data );
  }

  void free()
  {
    std::free( this->m_data );
    std::free( this );
  }

  void grow( std::size_t newSize )
  {
    if ( newSize <= this->m_size ) { return; }

    std::size_t oldSize = this->m_size;

    while ( this->m_size < newSize ) { this->m_size *=2; }

    this->m_data = static_cast< char* >( std::realloc(
                                       static_cast< void* >( this->m_data ),
                                       this->m_size ) );

    std::memset( static_cast< void* >( this->m_data + oldSize ), '\0', this->m_size - oldSize );
  }

  void grow()
  {
    this->grow( this->m_size * 2 );
  }

  void shrink()
  {
    this->m_size /= 2;
    this->m_size = MAX( this->m_size, STRSIZE );

    this->m_data = static_cast< char* >( std::realloc( static_cast< void* >( this->m_data ), this->m_size ) );

    this->m_data[ this->m_size - 1 ] = '\0';
  }

  void append( const char *data )
  {
    std::size_t length = std::strlen( this->m_data );

    this->grow( this->m_size + length );

    for ( std::size_t i = 0; i < std::strlen(data); i++ ) { this->m_data[ length + i ] = data[ i ]; }
  }

  void append( char data )
  {
    std::size_t length = std::strlen( this->m_data );

    if ( length >= this->m_size - 1 ) { this->grow(); }

    this->m_data[ length ] = data;
  }

  auto data() -> char*
  {
    return this->m_data;
  }

  auto getChar( std::size_t index ) -> char
  {
    if ( index >= this->m_size ) { return '\0'; }

    return this->m_data[ index ];
  }

  auto getSize()   -> std::size_t {        return this->m_size;         }
  auto getLength() -> std::size_t { return std::strlen( this->m_data ); }

  void set( const char *data )
  {
    this->grow( this->m_size + std::strlen( data ) );
    std::strcpy( this->m_data, data );
  }

};

auto main() -> int
{
  String string("Hey");

  string.grow();
  string.set("Hello");

  string.grow();
  string.append(" World!!");

  printf("String is: %s", string.data());

  return 0;
}
