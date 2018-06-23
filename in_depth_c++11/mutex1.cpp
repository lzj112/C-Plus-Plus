#include <iostream>
#include <thread>
#include  <mutex>
using namespace std;

mutex g_lock;

void func() 
{
    // g_lock.lock();
    lock_guard<mutex> q_lock(g_lock);
    cout << this_thread::get_id() << "hello word!" << endl;
    // g_lock.unlock();

}

int main() 
{
    thread t(func);
    thread t2(func);
    thread t3(func);

    t.join();
    t2.join();
    t3.join();
    return 0;
}