using size_t = unsigned long long int;
using intptr_t = long long int;

struct Memory
{
  char end asm("end"){};
  void *heapEnd = nullptr;

  constexpr Memory() {}

  constexpr void *systemBreak(intptr_t increment)
  {
    if ( this->heapEnd == nullptr )
    {
      this->heapEnd = &end;
    }

    void *previousHeapEnd = heapEnd;
    //heapEnd = (char*) heapEnd + increment;
    heapEnd = static_cast<char*>(heapEnd + increment);
    return previousHeapEnd;
  }

  constexpr Memory(size_t size)
  {
  void *result = this->systemBreak( 0 );
  //void *request = this->systemBreak( size );

  /*if ( request == (void*) -1 )
  {
    //return nullptr;
  }*/

  //return result;
  }
};

int main()
{
  static constinit Memory m(4);

  return 0;
}
