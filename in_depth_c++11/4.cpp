//获取当前线程的id　还可以获取CPU核心数量
#include <iostream>
#include <thread>
using namespace std;

void func() 
{
    cout << "here is func\n";
}

int main() 
{
    thread t(func);
    cout << t.get_id() << endl; //获取id

    //获取CPU核数，失败返回0
    cout << thread::hardware_concurrency() << endl;
    
    t.join();
    
    return 0;
}