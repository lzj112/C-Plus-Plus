//std::bind的基本用法
#include <iostream>
#include <functional>   //std::bind
using namespace std;

void call_when_even(int x, const function<void(int)>& f) 
{
    if (! (x & 1))  //x % 2 == 0 
    {
        f(x);
    }
}

void output(int x) 
{
    cout << x << " ";
}

void output_add_2(int x) 
{
    cout << x + 2 << " ";
}

int main() 
{
    {
        auto fr = bind(output, placeholders::_1);
        for (int i = 0; i < 10; i++) 
        {
            call_when_even(i, fr);
        }
        cout << endl;
    }

    {
        auto fr = bind(output_add_2, placeholders::_1);
        for (int i = 0; i < 10; i++) 
        {
            call_when_even(i, fr);
        }
        cout << endl;
    }
    return 0;
}