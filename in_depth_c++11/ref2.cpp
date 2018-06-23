#include <thread>
#include <iostream>
using namespace std;

void func(int& a) 
{
    a = 1;
}

int main() 
{
    int a = 100;

    thread t(func, ref(a));
    t.join();

    cout << a << endl;
    return 0;
}