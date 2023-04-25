template<typename Type, SIZE_T SIZE>
class Array
{
public:
  Type data[SIZE]{};
  const SIZE_T size = SIZE;

  constexpr Array(){}
  constexpr Array(Type data[SIZE])
  {
    for (unsigned index = 0; index <= SIZE; index++)
    {
      this->data[index] = data[index];
    }
  }

  template<typename... Args>
  constexpr Array(Args... args) : data{args...} {}
};

template<typename Type, SIZE_T SIZE>
Array(Type (&)[SIZE]) -> array<Type, SIZE>;
