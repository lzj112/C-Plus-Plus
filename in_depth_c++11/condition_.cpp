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
        while (IsFull()) 
        {
            cout << "缓冲区满了,需要等待．．．" << endl;
            m_notFull.wait(m_mutex);
        }

        m_queue.push_back(x);
        m_notEmpty.notify_one();
    }

    void Take(T& x) 
    {
        lock_guard<mutex> locker(m_mutex);
        while (IsEmpty()) 
        {
            cout << "缓冲区为空，需要等待..." << endl;
            m_notEmpty.wait();
        }

        x = m_queue.front();
        m_queue.pop_front();
        m_notFull.notify_one();
    }

    bool Empty() 
    {
        lock_guard<mutex> locker(m_mutex);
        return m_queue.empty();
    }

    bool Full() 
    {
        lock_guard<mute> locker(m_mutex);
        return m_queue.size() == m_maxSize;
    }

    size_t Size() 
    {
        lock_guard<mutex> locker(m_mutex);
        return m_queue.size();
    }

    int count() 
    {
        return m_queue.size();
    }

private:
    list<T> m_queue;        //缓冲区
    mutex m_mutex;          //互斥量和条件变量结合起来使用
    condition_variable_any m_notEmpty;  //不为空的条件变量
    condition_variable_any m_notFull;   //没有满的条件变量
    int m_maxSize;          //同步队列最爱的size
}