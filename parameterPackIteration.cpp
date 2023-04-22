template <class ... Ts>
void Foo (Ts && ... inputs)
{
    int i = 0;

    ([&]
    {
        //inputs; // if lambda empty you need this line to make it work
        ++i;
        std::cout << "input " << i << " = " << inputs << std::endl;

    } (), ...);
}

int main ()
{
    Foo(2, 3, 4u, (int64_t) 9, 'a', 2.3);
}
