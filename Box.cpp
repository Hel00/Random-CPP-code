template <typename T>
struct removeReference
{
    using type = T;
};

template <typename T>
struct removeReference<T&>
{
    using type = T;
};

template <typename T>
struct removeReference<T&&>
{
    using type = T;
};

template <typename T>
constexpr typename removeReference<T>::type &&move(T&& arg) noexcept
{
    return static_cast<typename removeReference<T>::type&&>(arg);
}

template <typename T>
constexpr T&& forward(typename removeReference<T>::type& arg) noexcept
{
    return static_cast<T&&>(arg);
}

template <typename T>
constexpr T&& forward(typename removeReference<T>::type&& arg) noexcept
{

    return static_cast<T&&>(arg);
}

template <typename T>
constexpr T&& _move(T &arg) noexcept
{
    return static_cast<T&&>(arg);
}

template <typename T, typename U = T>
constexpr T exchange(T& obj, U&& new_value)
{
    T old_value = _move(obj);
    obj = forward<U>(new_value);
    return old_value;
}

template<typename DataType>
struct Box
{
  // Data
  DataType *data = nullptr;

  // Constructors and destructors
  constexpr Box() = default;
  constexpr Box(DataType *data) : data(data) {}
  constexpr ~Box()
  {
    delete data;
    data = nullptr;
  }

  // Move operations
  constexpr Box(Box &&other) : data(exchange(other.data, nullptr)) {}
  constexpr Box &operator = (Box &&other)
  {
    delete data;
    data = nullptr;

    data = exchange(other.data, nullptr);
  }

  // Copy operators (they are deleted)
  constexpr Box(const Box&) = delete;
  constexpr Box &operator = (const Box&) = delete;
};

constexpr void boxTest()
{
  Box<int> data(new int());
}

int main() {}
