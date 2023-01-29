//#include <cstdio>

using size = long long int;
using intptr = long long int;

extern char end asm("end");

void *systemBreak( intptr increment )
{
  static void *heapEnd = nullptr;

  if ( heapEnd == nullptr )
  {
    heapEnd = &end;
  }

  void *previousHeapEnd = heapEnd;
  heapEnd = (char*) heapEnd + increment;
  return previousHeapEnd;
}

void *alloc( size size )
{
  void *result = systemBreak( 0 );
  void *request = systemBreak( size );

  if ( request == (void*) - 1 )
  {
    return nullptr;
  }

  return result;
}

int main() {
  int *pointer = (int*) alloc( sizeof( int ) );
  *pointer = 123;

  //printf( " pointer = %x\n",  pointer );
  //printf( "*pointer = %d\n", *pointer );
  return 0;
}
