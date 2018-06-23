#include <iostream>
#include <thread>
#include <vector>
using namespace std;

vector<thread> g_list;
vector<shared_ptr<thread>> g_list2;

void func() 
{
    cout << "here is func" << endl;
}

void CreateThread() 
{
    thread t(func);
    
    g_list.push_back(move(t));
    g_list2.push_back(make_shared<thread>(func));
}

int main() 
{
    CreateThread();
    for (auto& thread : g_list) 
    {
        thread.join();
    }

    for (auto& thread : g_list2) 
    {
        thread->join();
    }

    return 0;
}