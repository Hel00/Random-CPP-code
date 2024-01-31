#include <cstdio>

consteval auto structuredBindingReturn()
{
  struct Result
  {
    const char *data;
    unsigned long long size;

    constexpr Result(const char *d, unsigned long long s)
      : data(d), size(s) {}
  };

  Result result("ABC", 2);

  return result;
}

int main()
{
  static constexpr auto result = structuredBindingReturn();

  static constexpr struct
  {
    const char *data;
    unsigned long long size;

  } structuredBindingUnwrap{.data = result.data, .size = result.size};


  printf("data is: %s; and size is: %d",
    structuredBindingUnwrap.data,
    structuredBindingUnwrap.size);

  return 0;
}
