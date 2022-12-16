template <typename T, typename U>
struct _sameAs
{
    static constexpr bool value = false;
};

template <typename T>
struct _sameAs<T, T>
{
    static constexpr bool value = true;
};

template <typename T, typename U>
inline constexpr bool sameAs = _sameAs<T, U>::value;

template<typename T>
concept Number = sameAs<T, int> || sameAs<T, double>;

int main()
{
    Number auto x = 1;
    Number auto y = 1.1;
    //Number auto z = '1'; // error: deduced type 'char' does not satisfy 'Number'

    return 0;
}

// Expansion:

template <typename T, typename U>
concept SameAs = requires
{
    sameAs<T, U>;
};

template<typename T>
concept AddableInt = requires (T a, T b)
{
    { a + b } -> SameAs<int>;
};
