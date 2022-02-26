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