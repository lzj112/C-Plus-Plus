#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    vector<vector<string>> vv;
    vector<string> v = {"123", "456"};
    v.push_back("789");
    vv.push_back(v);
    for (auto x : v) 
    {
        cout << x << endl;
    }
}