//利用c++11的原子操作实现自旋锁
//c++11提供了对原子操作的支持，其中std::atomic是标准库提供的一个原子类模板
//可以用来声明一个自旋锁互斥对象spin_mutex
#include <atomic>

class spin_mutex 
{
    std::atomic<bool> flag = ATOMIC_VAR_INIT(false);
public:
    spin_mutex() = default;
    spin_mutex(const spin_mutex&) = delete;
    spin_mutex& operator=(const spin_mutex&) = delete;
    void lock(); //获取自旋锁
    void unlock(); //释放自旋锁
};