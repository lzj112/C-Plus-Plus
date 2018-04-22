#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() 
{
    vector<int> a;
    fill_n(back_inserter(a), 10, 0);
    for (int x : a) 
    {
        cout << x;
    }
    cout << endl;
}