#include <iostream>
using namespace std;

template<class T>
class A 
{
public:
    A() : val(1){}
    T val;
template<class Q>
    friend void show(Q a);
};

template<class Q, class T>
void show(Q a, A<T>& aa) 
{
    cout << a << endl 
         << aa.val << endl;
}

int main() 
{
    A<int> a;
    string str = "asasas";
    show(str, a);

    return 0;
}