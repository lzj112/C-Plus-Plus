#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    vector<int> a{-1, -2, 2, 3, -5, 10, 0};
    transform(a.begin(), a.end(), a.begin(), 
             [](int i) ->int
             {if (i < 0) return -i;else return i;});
    for (int x : a) 
    {
        cout << x << endl;
    }
   
}
