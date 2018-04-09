#include <iostream>
using namespace std;
const double PI=3.1415926;

class Circle
{
protected:
   double radius;
   Circle(double r)
   {
      radius = r;
   }
   double getArea()
   {
      return PI * radius * radius;
   }
};
class Cylinder : public Circle 
{
private:
    double h;
public:
    Cylinder(double r, double h);
    double getArea();
};
Cylinder::Cylinder(double r, double h) : Circle(r)
{
    this->h = h;
}
double Cylinder::getArea()
{
    return ((2 * PI * radius * radius) + (2 * PI * radius) * h);
}