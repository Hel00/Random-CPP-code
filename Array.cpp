template<typename T>
struct add_rvalue_reference
{
    using type = T;
};

template<typename T>
using add_rvalue_reference_t = typename add_rvalue_reference<T>::type;

template<typename T>
add_rvalue_reference_t<T> declval() noexcept;

template<typename... Args>
struct CommonType;

template<typename T>
struct CommonType<T>
{
    using Type = T;
};

template<typename T, typename... Args>
struct CommonType<T, Args...>
{
    using Type = decltype(true ? declval<T>() : declval<typename CommonType<Args...>::Type>());
};

template<typename... Args>
using CommonType_t = typename CommonType<Args...>::Type;

template<typename Type, SIZE_T SIZE>
class array
{
public:
  Type data[SIZE]{};

  constexpr array(){}
  constexpr array(Type data[SIZE])
  {
    for (unsigned index = 0; index <= SIZE; index++)
    {
      this->data[index] = data[index];
    }
  }

  template<typename... Args>
  constexpr array(Args... args) : data{args...} {}

  constexpr Type *begin() const {    return (Type*)this->data;     }
  constexpr Type *end() const   { return (Type*)this->data + SIZE; }

private:
  const SIZE_T size = SIZE;
};

template<typename Type, SIZE_T SIZE>
array(Type (&)[SIZE]) -> array<Type, SIZE>;

template<typename... Args>
array(Args...) -> array<CommonType_t<Args...>, sizeof...(Args)>;
