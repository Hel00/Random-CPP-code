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
};

template<>
struct Option<void>
{
  constexpr Option() {}

  constexpr bool hasValue() const { return false; }
};

constexpr Option<void> None() { return Option<void>(); }

template<typename T>
constexpr Option<T> Some(const T value) { return Option<T>(value); }

template<typename ...Type>
void process(Option<Type> ...options)
{
  ([&]
  {
    std::cout << options.hasValue() << std::endl;
  } (), ...);
}

int main()
{
  static constexpr Option optionSome = Some(42);
  static constexpr Option optionNone = None();

  process(optionSome, optionNone);
}
