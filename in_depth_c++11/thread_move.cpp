#include <iostream>
#include <thread>
using namespace std;

void func() 
{
    cout << "here is func\n";
}

int main() 
{
    thread t(func);
    thread q(move(t));
    // t.join();
    q.join();

    return 0;
}