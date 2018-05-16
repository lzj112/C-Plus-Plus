#include <iostream>
using namespace std;
const double PI=3.14;

class Shape {
	public:
		virtual double getArea()=0;
		virtual double getPerim()=0;
};

/* ------请在这里填写答案 ------*/
class Rectangle : public Shape 
{
    double w, h;
public:
    Rectangle(double a, double b) : w(a), h(b){

    }
    double getArea() 
    {
        return w * h;
    }
    double getPerim() 
    {
        return (w+h) * 2;
    }
};
class Circle : public Shape 
{
    double r;
public:
    Circle(int a) : r(a){

    }
    double getArea() 
    {
        return 3.14*r*r;
    }
    double getPerim() 
    {
        return 2*r*3.14;
    }

};

int main() {
	Shape *p;
	int n;
	double w,h,r;
	scanf("%d",&n);
	switch(n) {
		case 1: {
			cin>>w>>h;
			Rectangle rect(w,h);
			cout<<"area="<<rect.getArea()<<endl;
			cout<<"perim="<<rect.getPerim()<<endl;
			break;
		}
		case 2: {
			cin>>r;
			Circle c(r);
			cout<<"area="<<c.getArea()<<endl;
			cout<<"perim="<<c.getPerim()<<endl;
			break;
		}
	}

	return 0;
}