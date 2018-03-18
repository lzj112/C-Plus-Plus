#include<iostream>
#include<vector>
using namespace std;
vector < string > process(int a, int b)
{
    string str = "i";
    string ctr = " love u";
    if (a > b) 
    {
        return {};
    }
    else if (a == b) 
    {
        return {"aaa", "bbb", "ccc"};
    }
    else 
    {
        return {str, ctr};
    }
}
int main()
{
    auto x = process(1, 2);
    for (auto i : x) 
    {
        cout << i << ' ';
    }
    cout << endl;
    x = process(1, 1);
    for (auto i : x) 
    {
        cout << i << ' ';
    }
    cout << endl;
    x = process(2, 1);
    for (auto i : x)
    {
        cout << i << ' ';
    }
    cout << endl;
}