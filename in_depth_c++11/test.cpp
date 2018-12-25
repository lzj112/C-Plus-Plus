#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

once_flag onlyOnce;
mutex myMutex;

void func() 
{
    myMutex.lock();
    cout << "here is func" << endl;
    myMutex.unlock();

    call_once(onlyOnce, []{
        cout << "hello world!" << endl;
    });
}

int main() 
{
    thread t1(func);
    thread t2(func);
    thread t3(func);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}