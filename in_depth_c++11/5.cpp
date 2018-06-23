#include <unistd.h>
#include <thread>
#include <iostream>
using namespace std;

void func() 
{
    // this_thread::sleep_for(chrono::seconds(3));
    cout << "time out \n";
}

int main() 
{
    thread t(func);
    t.detach();

    int i = 10;
    while (i--) 
    {
        cout << i << endl;
    }
    cout << "thread id : " << t.get_id() << endl;
    
    sleep(1);
    return 0;
}