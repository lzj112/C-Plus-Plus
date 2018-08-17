#include <list>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>
using namespace std;

template<class T>
class SyncQueue 
{
public:
    //初始化 m_needStop为true时终止
    SyncQueue(int maxSize) : m_maxSize(maxSize), m_needStop(false) {}

    //添加任务．参数为左值引用
    void Put(const T& x) 
    {
        Add(x);
    }
    //重载，使用完美转发保持右值引用属性传给Add()
    void Put(T&& x) 
    {
        Add(std::forward<T>(x));
    }
    
    //取任务，可以一次取多个任务，提高效率
    void Take(std::list<T>& list) 
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        //wait条件：执行或者队列不为空
        m_notEmpty.wait(locker, [this]{return m_needStop || NotEmpty();}); 

        if (m_needStop) //如果为终止
        {
            return ;
        }
        list = std::move(m_queue);  //将m_queue的资源直接移动给list
        m_notFull.notify_one(); //唤醒因为队列满而阻塞的添加任务的线程
    }

    //一次取一个任务，效率较低
    void Take(T& t) 
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        m_notEmpty.wait(locker, [this]{return m_needStop || NotEmpty();}); 

        if (m_needStop) 
        {
            return ;
        }
        t = m_queue.front();    //取走队头一个任务
        m_queue.pop_front();
        m_notFull.notify_one();
    }

    void Stop() //终止
    {
        {
            //lock_guard在这个无名空间内得到锁，生命周期只在这个空间内
            std::lock_guard<std::mutex> locker(m_mutex);
            m_needStop = true;
        }   //lock_guard 已将锁释放

        m_notFull.notify_all(); //唤醒所有线程
        m_notEmpty.notify_all();
    }

    //判断队列是否为空
    bool Empty() 
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.empty();
    }
 
    //判断队列是否满了
    bool Full() 
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size() == m_maxSize;
    }

    //得到任务队列的任务数量
    size_t Size() 
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        return m_queue.size();
    }

    int count() 
    {
        return m_queue.size();
    }

private:
    bool NotFull() const 
    {
        bool full = m_queue.size() >= m_maxSize;
        if (full) 
        {
            cout << "缓冲区满了, 需要等待..." << endl;
        }
        return !full;
    }

    bool NotEmpty() const 
    {
        bool empty = m_queue.empty();
        if (empty) 
        {
            cout << "缓冲区空了, 需要等待..." << endl;
        }
        return !empty;
    }

    //添加任务　泛型事件函数
    template<class F>
    void Add(F&& x) 
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        //wait条件:执行或者队列满
        m_notFull.wait(locker, [this]{return m_needStop || NotFull();}); 
        if (m_needStop) //如果是终止
        {
            return ;
        }
        m_queue.push_back(std::forward<F>(x));
        m_notEmpty.notify_one(); //唤醒因队列空而阻塞的取任务的线程
    }

private:
    list<T> m_queue;           //缓冲区
    mutex m_mutex;             //互斥量和条件变量结合起来使用
    condition_variable m_notEmpty;      //不为空的条件变量
    condition_variable m_notFull;       //没有满的条件变量
    int m_maxSize;             //同步队列最大的size
    bool m_needStop;           //停止的标志
};
/*
condition_variable 只能和 unique_lock配合使用
*/