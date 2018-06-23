#include <iostream>
#include <functional>
#include <thread>

using namespace std;

void func(int a, double b) 
{
    cout << a << ' ' << b << endl;
}
int main() 
{
    thread t1(bind(func, 1, 2));
    thread t2([](int a, double b){cout << a << ' ' << b << endl;}, 1, 2);
    t1.join();
    t2.join();

    return 0;
}