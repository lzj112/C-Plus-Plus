#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic<int> foo(0);

//memroy_order_relaxed 无副作用的同步
//仅要求操作是原子的 

void set_foo(int x) 
{
    foo.store(x, memory_order_relaxed); //添加值
}

void print_foo() 
{
    int x;
    do {
        x = foo.load(memory_order_relaxed);
    } while (x == 0);
    cout << "foo = " << x << endl;
}
int main() 
{
    thread first(print_foo);
    thread second(set_foo, 10);
    first.join();
    second.join();
    return 0;
}