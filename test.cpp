#include <iostream>
#include <array>
#include <unistd.h>
#include <thread>
#include <mutex>
using namespace std;

int num = 0;

class A 
{
public:
    static void show(int a) 
    {
        cout << a << endl;
    }
};

class B 
{
public:
    void show(int a) 
    {
        A::show(a);
    }
};

int main() 
{
    B b;
    b.show(10);
}