#include <iostream>
using namespace std;

void show() 
{
    int i = 10;
    i = [=]() mutable -> int
    {
        cout << "here is fun "<< i << endl;
        ++i;
        return i;
    }();
    cout << i << endl;
}
int main() 
{
    show();
}