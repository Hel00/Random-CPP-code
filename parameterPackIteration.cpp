template <class ... Ts>
void Foo (Ts && ... inputs)
{
    int i = 0;

    ([&]
    {
        // Do things in your "loop" lambda

        ++i;
        std::cout << "input " << i << " = " << inputs << std::endl;

    } (), ...);
}

int main ()
{
    Foo(2, 3, 4u, (int64_t) 9, 'a', 2.3);
}
