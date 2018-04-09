#include <iostream>
#include <math.h>
using namespace std;
class shape 
{
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
};
class RTriangle : public shape 
{
private:
    double a, b;
public:
    RTriangle(double a, double b);
    double getArea();
    double getPerimeter();
};
RTriangle::RTriangle(double a, double b) 
{
    this->a = a;
    this->b = b;
}
double RTriangle::getArea() 
{
    return a * b / 2;
}
double RTriangle::getPerimeter() 
{
    return (a + b + sqrt(pow(a, b)));
}

int main()
{
  double a,b;
  cin>>a>>b;
  RTriangle t(a,b);
  cout<<t.getArea()<<endl;
  cout<<t.getPerimeter()<<endl;	
}