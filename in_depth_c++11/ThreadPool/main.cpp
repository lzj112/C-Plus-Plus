#include <iostream>
#include "ThreadPool.hpp"
using namespace std;

void TestThdPool() 
{
    //线程池创建2个线程
    ThreadPool pool(2);

    //创建两个线程，不断向任务队列添加任务,在本例子中任务就是函数
    thread thd1([&pool]
    {
        for (int i = 0; i < 10; i++) 
        {
            auto thdID = this_thread::get_id();
            pool.AddTask([thdID] 
            {
                cout << "同步层线程１的线程ＩＤ: " << thdID << endl;
            });
        }
    });

    thread thd2([&pool] 
    {
        for (int i = 0; i < 10; i++) 
        {
            auto thdID = this_thread::get_id();
            pool.AddTask([thdID] 
            {
                cout << "同步层线程２的线程ＩＤ: " << thdID << endl;
            });
        }
    });

    this_thread::sleep_for(chrono::seconds(2));
    // getchar();  

    //终止线程池
    pool.Stop();

    //等待两个线程
    thd1.join();
    thd2.join();
}

int main() 
{
    TestThdPool();
    return 0;
}