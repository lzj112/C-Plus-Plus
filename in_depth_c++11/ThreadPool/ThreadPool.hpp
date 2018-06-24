#include <list>
#include <thread>
#include <functional>
#include <memory>
#include <atomic>
#include "SyncQueue.hpp" 

const int MaxTaskCount = 100;

class ThreadPool 
{
public:
    //Task是一个无参无返回值的函数模板,当然也可以是别的类型，这里只是一个例子
    using Task = std::function<void()>;

    //numThreads默认参数是cpu核数
    ThreadPool(int numThreads = std::thread::hardware_concurrency()) : m_queue(MaxTaskCount) 
    {
        Start(numThreads);
    }

    void Stop() 
    {
        //保证多线程情况下只调用一次StopThreaadGroup
        std::call_once(m_flag, [this]{StopThreadGroup();});
    }

    void AddTask(Task&& task) //添加任务的两个重载
    {
        m_queue.Put(std::forward<Task>(task));
    }

    void AddTask(const Task& task) 
    {
        m_queue.Put(task);
    }

private:
    //创建线程，
    void Start(int numThreads) 
    {
        m_running = true;
        //创建线程组
        for (int i = 0; i < numThreads; i++) 
        {
            m_threadgroup.push_back(std::make_shared<std::thread>(&ThreadPool::RunInThread, this));
        }
    }

    //线程函数
    void RunInThread() 
    {
        while (m_running) 
        {
            //取任务分别执行
            std::list<Task> list;
            m_queue.Take(list);

            for (auto& task : list) 
            {
                if (!m_running) //如果终止
                {
                    return ;
                }
                task(); //执行任务函数
            }
        }
    }

    void StopThreadGroup() 
    {
        m_queue.Stop();
        m_running = false;      //让同步队列中的线程停止

        for (auto thread: m_threadgroup)    //等待线程结束
        {
            if (thread) 
            {
                thread->join();
            }
        }
        m_threadgroup.clear();
    }

private:
    std::list<std::shared_ptr<std::thread>> m_threadgroup;  //处理任务的线程组
    SyncQueue<Task> m_queue;        //同步队列
    atomic_bool m_running;          //是否停止的标志
    std::once_flag m_flag;     
};