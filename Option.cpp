#include <iostream>

using std::cout;
using std::endl;

template<typename T>
struct Option
{
  T data;

  constexpr Option(const T value) : data(value) {}
  constexpr Option(const T &&value) : data(value) {}

  constexpr bool hasValue() const { return true; }
  constexpr T getData() const { return data; }
};

template<>
struct Option<void>
{
  constexpr Option() {}

  constexpr bool hasValue() const { return false; }
  constexpr bool getData() const { return false; }
};

constexpr Option<void> None() { return Option<void>(); }

template<typename T>
constexpr Option<T> Some(const T value) { return Option<T>(value); }

template<typename ...Type>
constexpr void process(Option<Type> ...options)
{
  ([&]
  {

    if constexpr ( options.hasValue() == true )
    {
      std::cout << options.getData() << std::endl;
    }
    else {}

  } (), ...);
}

int main()
{
  static constexpr Option optionSome = Some(42);
  static constexpr Option optionNone = None();

  process(optionSome, optionNone);
}



// OR



#include <iostream>

template<typename T>
struct Option
{
  T data;

  constexpr Option(T data) : data(data) {}

  constexpr bool hasValue() { return true; }
  constexpr T getData() { return this->data; }
};

template<>
struct Option<void>
{
  struct None{};

  constexpr Option() = default;

  constexpr bool hasValue() { return false; }
  constexpr None getData() { return None{}; }
};

template<typename T>
Option(T data) -> Option<T>;
Option() -> Option<void>;

template<typename ...Type>
constexpr void process(Option<Type> ...options)
{
  ([&]
   {
     if constexpr ( options.hasValue() == true )
     {
       std::cout << options.getData() << std::endl;
     }
     else {}

   } (), ...);
}

int main()
{
  static constexpr Option some(42);
  static constexpr Option none;

  process(some, none);
}
