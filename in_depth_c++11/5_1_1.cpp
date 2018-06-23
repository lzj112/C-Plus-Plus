#include <thread>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
void func() 
{
    std::cout << "herer is func" << std::endl;
}

void func2(int i, double d, const std::string& s) 
{
    std::cout << i << ' ' << d << ' ' << s << ' ' << std::endl;
    std::cout << std::this_thread::get_id() << std::endl; //这个也只是对pthread_self的封装
    std::cout << pthread_self() << std::endl;
}

int main() 
{
    // std::thread t(func);
    // t.join();
    // t.detach();
    std::thread t(func2, 1, 2.6, "i love u!");
    t.join();
    return 0;
}