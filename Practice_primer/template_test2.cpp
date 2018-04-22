#include <iostream>
using namespace std;
template<class T> 
T compare(T a, T b, T c) 
{
    T tmp;
    if ((a < b) && (a <c )) 
    {
        tmp = a;
    }
    else if ((b < a) && (b < c)) 
    {
        tmp = b;
    }
    else 
    {
        tmp = c;
    }
    return c;
}
int main()
{
    cout << compare("anderson","Washington","Smith") << endl;
    cout << compare(string("anderson"), string("Washington"), string("Smith")) << endl;
    char* p ="abcde";
    char* t = "qweer";
    if (p > t) cout << "1\n";
    else  cout << "2\n";
}