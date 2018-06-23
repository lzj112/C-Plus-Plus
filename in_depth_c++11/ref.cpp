#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class aa 
{
public:
    int a;
};

void func(int& a, string& b, aa& c) 
{
    a = 0;
    b = "hello";
    c.a = 0;

    cout << "here is func : " << a << ' ' << b << ' ' << c.a << endl;
}

int main() 
{
    int a = 1;
    string b = "qwer";
    aa c;
    c.a = 1;

    cout << "in main before func : " << a << ' ' << b << ' ' << c.a << endl;
    
    thread t(func, a, b, c);
    t.join();

    cout << "in main after func : " << a << ' ' << b << ' ' << c.a << endl;
    return 0;
}