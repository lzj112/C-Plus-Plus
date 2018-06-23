#include <iostream>
using namespace std;
int main() 
{
    int x = 10;
    auto f = [=] () mutable {return x;};
    x++;
    cout << f() << endl;
}