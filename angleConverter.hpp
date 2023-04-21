class Angle
{
public:
  char degrees;
  char minutes;
  char seconds;

  constexpr Angle(char degrees, char minutes, char seconds)
  {
    this->degrees = degrees;
    this->minutes = minutes;
    this->seconds = seconds;
  }

  constexpr Angle(double data)
  {
    this->degrees = char(data);
    this->minutes = char((data - degrees) * 60.0);
    this->seconds = (data - degrees - minutes / 60.0) * 3600.0;
  }

  constexpr double toRadian()
  {
    return degrees + (minutes / 60.0) + (seconds / 3600.0);
  }
};

#include <iostream>

using std::cout;
using std::endl;

int main()
{
  Angle inRadian(1.337);
  Angle inDegrees(20, 13, 11);

  cout << "From radian to degrees: "
       << (int) inRadian.degrees << ' '
       << (int) inRadian.minutes << ' '
       << (int) inRadian.seconds << ' '
       << endl;

  cout << "From degrees to radian: "
       << inDegrees.toRadian()
       << endl;
}
