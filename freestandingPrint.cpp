// zig build-exe -O ReleaseSmall -ffunction-sections --gc-sections --entry Main freestandingPrint.cpp
// z++ -eMain --target=x86_64-freestanding-none -Oz -s -ffunction-sections freestandingPrint.cpp
// clang++ -std=c++20 -Oz -s -eMain -fuse-ld=lld --target=x86_64-freestanding-none -fPIC -nostdinc -nostartfiles -ffunction-sections -fdata-sections -Wl,--gc-sections -static freestandingPrint.cpp

using size_t = long long int;

template< typename T = int >
constexpr T stringToInt( char const *const stream )
{
  T result = 0;

  for ( int index = 0; stream[ index ] != '\0'; index++ )
  {
    result *= 10;
    result += stream[ index ] - '0';
  }

  return result;
}

constexpr int streamLength( const char *stream )
{
  int index = 0;

  while ( stream[ index ] != '\0' )
  {
    index++;
  }

  return index;
}

long write( int fileDescriptor, const char *stream, size_t size )
{
  static constexpr int SYSCALL_NUMBER_WRITE = 1;

  long result;

  asm volatile
  (
    "syscall"
    : "=a"( result )
    : "0"( SYSCALL_NUMBER_WRITE ), "D"( fileDescriptor ), "S"( stream ), "d"( size )
    : "rcx", "r11", "memory"
  );
}

extern "C" int Main()
{
  constexpr const char *data = "Hello, world! :)\n";

  write( 1, data, streamLength( data ) );

  return 0;
}
