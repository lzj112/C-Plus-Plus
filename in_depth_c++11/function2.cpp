#include <iostream>
#include <functional>
using namespace std;

class A 
{
    function<void()> callback_;
public:
    A(const function<void()>& f) : callback_(f) {}
    void notify(void) 
    {
        callback_();    //回调到上层
    }
};

class Foo 
{
public:
    void operator()(void) 
    {
        cout << __FUNCTION__ << endl;
    }
};

int main(void) 
{
    Foo foo;
    A aa(foo);
    aa.notify();

    return 0;
}