#include <iostream>
#include <array>
#include <unistd.h>
#include <thread>
#include <mutex>
using namespace std;

int num = 0;

void fun1() 
{
    mutex lock1;
    lock1.lock();
    while (1)
    {
        num++;
        cout << num << "******here is fun1" << endl;
        sleep(1);
    }
    lock1.unlock();
}

void fun2() 
{
    mutex lock2;
    lock2.lock();
    while (1)
    {
        num++;
        cout << num << "------------here is fun2" << endl;
        sleep(1);
    }
    lock2.unlock();
}
int main() 
{ 
    thread t1(fun1);
    thread t2(fun2);

    t1.join();
    t2.join();
} 