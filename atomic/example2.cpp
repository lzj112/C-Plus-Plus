#include <atomic>
#include <iostream>
#include <thread>
using namespace std;

atomic<int> foo(0);

void set_foo(int x) 
{
    foo = x;
}

void print_foo() 
{
    while (foo == 0) //等待set_foo
    {
        this_thread::yield();
    }
    cout << "foo = " << foo << endl;
}
int main() 
{
    thread first(print_foo);
    thread second(set_foo, 10);
    first.join();
    second.join();
    return 0;
}