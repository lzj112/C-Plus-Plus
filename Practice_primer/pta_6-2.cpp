#include <iostream>
using namespace std;
class shape {

public:
double getArea(){ return -1; };

double getPerimeter(){ return -1 };

};

class Circle : public shape 
{
private:
    double radius;
public:
    Circle(double tmp);
    double getArea();
    double getPerimeter();
};
Circle::Circle(double tmp) 
{
    radius = tmp;
}
double Circle::getArea() 
{
    const double PI = 3.1415926;
    return PI * radius * radius;
}
double Circle::getPerimeter() 
{
    const double PI = 3.1415926;
    return 2 * radius * PI;
}

