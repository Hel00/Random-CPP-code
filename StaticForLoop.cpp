template <int First, int Last>
struct static_for
{
    template <typename Fn>
    void operator()(Fn const& fn) const
    {
        if (First < Last)
        {
            fn(First);
            static_for<First+1, Last>()(fn);
        }
    }
};

template <int N>
struct static_for<N, N>
{
    template <typename Fn>
    void operator()(Fn const& fn) const
    { }
};

int main()
{
    static_for<0, 20>()([&](int i)
    {            
        asm(
            "nop"
        );
    });
}

/* OR THIS */

#include <concepts>

template <int First, int Last>
struct static_for
{
    template <typename Lambda>
    static inline constexpr void apply(Lambda const& f)
    {
        if constexpr (First < Last)
        {
            f(std::integral_constant<int, First>{});
            static_for<First + 1, Last>::apply(f);
        }
    }
};

template <int N>
struct static_for<N, N>
{
    template <typename Lambda>
    static inline constexpr void apply(Lambda const& f) {}
};

int main()
{
    static_for<0, 10>::apply([&](auto i)
    {            
        asm("nop");
    });
}
