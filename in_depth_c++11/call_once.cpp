//多线程环境中某个函数仅被调用一次
//例；初始化某个对象，而这个对象只能初始化一次
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

once_flag flag;
void do_once() 
{
    call_once(flag, []{cout << "Called once " << endl;});
}

int main() 
{
    thread t1(do_once);
    thread t2(do_once);
    thread t3(do_once);

    t1.detach();
    t2.detach();
    t3.detach();
    // t1.join();
    // t2.join();
    // t3.join();
    int i = 3;
    while (i--) 
    {
        string s;
        cin >> s;
    }
    return 0;
}