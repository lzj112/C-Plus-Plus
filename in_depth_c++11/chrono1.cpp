#include <iostream>
#include <chrono>
using namespace std;

int main() 
{
    chrono::milliseconds ms{3}; //3毫秒

    chrono::microseconds us = 2 * ms;   //6000微妙

    chrono::duration<double, ratio<1, 30>> hz30{3.5};

    cout << "3ms duration has " << ms.count() << " ticks\n"
         << "6000 us duration has " << us.count() << " ticks\n";
}