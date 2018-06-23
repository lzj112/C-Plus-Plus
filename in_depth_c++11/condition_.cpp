//用条件变量实现的同步队列
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

template<class T>
class SyncQueue 
{
    bool IsFull() const 
    {
        return m_queue.size() == m_maxSize;
    }

    bool IsEmpty() const 
    {
        return m_queue.empty();
    }

public:
    SyncQueue(int maxSize) : m_maxSize(maxSize) {}
    
    void Put(const T& x) 
    {
        lock_guard<mutex> locker(m_mutex);
    }

private:
    list<T> m_queue;    //缓冲区
    mutex
}