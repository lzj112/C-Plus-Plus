#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
using namespace std;

atomic<bool> ready (false);
atomic_flag winner = ATOMIC_FLAG_INIT; //未定义

void fun(int id) 
{
    //线程先后创建出来阻塞，等待主线程(main里)改变ready
    while (!ready) //ready是原子类型，不同线程访问和改变其数据不会导致数据竞争
    {
        //std::this_thread::yield(); 
        //是将当前线程所抢到的CPU”时间片A”让渡给其他线程(其他线程会争抢”时间片A”, 
        //注意: 此时”当前线程”不参与争抢). 
        //如果没有其他线程，继续执行 
        //等到其他线程使用完”时间片A”后, 再由操作系统调度, 当前线程再和其他线程一起开始抢CPU时间片.
        //这个线程是暂停了，下次继续执行yield下面的代码
        this_thread::yield();
    }
    //volatile关键字修饰的变量，告诉编译器这个变量随时可能被改变，编译器不再针对访问它的代码
    //进行优化，从而可以提供对特殊地址的稳定访问
    //即，系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据
    for (volatile int i = 0; i < 10000000; ++i) {

    }
    if (!winner.test_and_set()) //没有被设置过，返回flase并设置为true
    {
        cout << "thread #" << id << "won!\n";
    }
    
}

int main() 
{
    vector<thread> threads;
    cout << "spawning 10 threads that count to 1 million...\n";
    for (int i = 1; i <= 10; i++) 
    {
        threads.push_back(thread(fun, i));
    }
    ready = true;
    for (auto& th : threads) 
    {
        th.join();
    }
    return 0;
}
