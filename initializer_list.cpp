template<typename T, unsigned long long SIZE>
struct Array
{
  T data[ SIZE ];

  T *begin() {    return data;     }
  T *end()   { return data + SIZE; }
};

#include <cstdio>

int main()
{
  Array<char, 5> array{ 2, 4, 6, 8, 10 };

  for ( const char &data : array )
  {
    printf("`array` contains: %d\n", data);
  }
}
