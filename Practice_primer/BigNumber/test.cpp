#include <iostream>
using namespace std;
class tmp 
{
private:
    int a;
public:
    tmp(int b) { a = b; }
    tmp& operator++(); //这是前缀
    const tmp operator++(int);  //这是后缀
    void show();
};

tmp& tmp::operator++() 
{
    this->a += 1;
    return *this;
}

const tmp tmp::operator++(int) 
{
    tmp old = *this; //先拿到自增前的值
    this->a += 1; //再自增 
    return old;
}

void tmp::show() 
{
    int i = 1;
    cout << "++a\n"
         << ++a + i << endl;
    cout << "a++\n"
         << i + a++ << endl;
}
int main()
{
    int i = 1;
    tmp a(1);
    a.show();
}