// g++ -static-libgcc -static-libstdc++ networking.cpp

#include <sugar>
#include <array>
#include <cstdio>

class Ipv4
{
private:
    i32 ip;
public:
    Ipv4(i32 ip);
    ~Ipv4();
    std::array<ui8, 4> getOctet();
};

Ipv4::Ipv4(i32 ip)
{
    this->ip = ip;
}

Ipv4::~Ipv4() {}

std::array<ui8, 4> Ipv4::getOctet()
{
    std::array<ui8, 4> octet = {0,0,0,0};

    for ( int i = 0; i < 4; i++ )
    {
        octet[i] = ( this->ip >> ( i * 8 ) ) & 0xFF;
    }

    return octet;
}

int main(int argc, char const *argv[])
{
    Ipv4 address(3232235537);
    std::array<ui8, 4> addressOctet;
    addressOctet = address.getOctet();
    printf("%d %d %d %d ", addressOctet[0], addressOctet[1], addressOctet[2], addressOctet[3]);
    return 0;
}
