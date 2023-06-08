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

template<typename T>
constexpr Option<void> None() { return Option<void>(); }

template<typename T>
constexpr Option<T> Some(const T value) { return Option<T>(value); }

int main()
{
  static constexpr Option x = Some(42);
  static constexpr auto result = x.hasValue();

  return result;
}
