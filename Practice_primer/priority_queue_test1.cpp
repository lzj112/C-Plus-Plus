#include <iostream>
#include <queue>
using namespace std;
int main() 
{
    priority_queue<string> q;
    string str;
    for (int i = 0; i < 5; i++) 
    {
        cin >> str;
        q.push(str);
    }
    cout << "----------------\n";
    for (;!q.empty();) 
    {
        cout << q.top() << endl;;
        q.pop();
    }
}