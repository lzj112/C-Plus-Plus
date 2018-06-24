#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
    vector<int> a{9, 8, 34, 3, 1, 0, 23, 45, 67, 57, 23};
    sort(a.begin(), a.end(), [](const int& a, const int& b)
    {
        return a > b ? : true, false;
    });
    for (int x : a) 
    {
        cout << x << endl;     
    }
}