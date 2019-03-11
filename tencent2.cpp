#include <iostream>
using namespace std;


long subCount(long l, long r) 
{
    if (l == r) 
        return (l % 2 == 0) ? l : -l;
    else
    {
        long a, b;
        a = (l % 2 == 0) ? l / 2 : -((l + 1) / 2);
        b = (r % 2 == 0) ? r / 2 : -((r + 1) / 2);
        return (l == 1) ? b : a + b;
    }
    
}

int main() 
{
    int q;
    cin >> q;
    long l, r;
    while (q--) 
    {
        cin >> l
            >> r;
        cout << subCount(l, r) << endl;
    }
}