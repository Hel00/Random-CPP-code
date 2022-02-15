const double ANGLE_PI = 3.14159265358979323846264338327950288419716939937510;

class Angle
{
private:

public:
    int degrees_m,
        minutes_m,
        seconds_m;
    Angle( int degrees,
           int minutes,
           int seconds )
           : degrees_m(degrees),
             minutes_m(minutes),
             seconds_m(seconds) {}

    Angle(double decimalAngle);

    ~Angle() {}

    double ToDec();
};

Angle::Angle(double decimalAngle)
{
    double degrees,
        minutes,
        seconds;

    degrees = decimalAngle;
    degrees = (degrees - (int)degrees) * 60;
    degrees_m = (int)degrees;

    minutes = degrees;
    minutes = (degrees - (int)minutes) * 60;
    minutes_m = (int)minutes;

    seconds = minutes;
    seconds = (minutes - (int)seconds) * 60.0;
    seconds_m = (int)seconds;
}

double Angle::ToDec()
{
    double degrees,
          minutes,
          seconds;

    seconds = seconds_m / 60.0;
    minutes = (minutes_m + seconds) / 60.0;
    degrees = degrees_m + minutes;

    return degrees;
}

/* TEST */

/*
#ifdef debug

    #include <iostream>
    #define dbgOut std::cout

#else

    #define dbgOut

#endif

#include "angleConverter.hpp"

int main()
{
    Angle angleA(20, 13, 11);
    Angle angleB(1.337);

    dbgOut << angleA.ToDec()
           << std::endl;

    dbgOut << angleB.degrees_m << " "
           << angleB.minutes_m << " "
           << angleB.seconds_m << " "
           << std::endl;
}
*/