#include <iostream>
#include <thread>

using namespace std;

void func(int a, double b)  //有参数
{
    cout << a << ' ' << b << endl;
}

void func2() //无参数
{
    cout << "hello!\n";
}

int main() 
{
    thread t1(func, 1, 2);
    thread t2(func2);

    //可以使用 lambda表达式
    thread t3([](int a, double b){cout << a << ' ' << b << endl;}, 3, 4);

    cout << t1.get_id()  << "****" << endl;
    t1.join();
    t2.join();
    t3.join();

    return 0;
}