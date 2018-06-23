#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// mutex g_lock;

int main() 
{
    recursive_mutex q_lock;

    q_lock.lock();
    cout << "here is first req" << endl;

    q_lock.lock();
    cout << "here is second req" << endl;

    q_lock.lock();
    cout << "here is third req" << endl;

    // q_lock.unlock();
    // q_lock.unlock();
    // q_lock.unlock();

    return 0;
}
