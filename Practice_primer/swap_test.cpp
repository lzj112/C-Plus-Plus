#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    vector<int> a{1, 3, 5, 7, 9};
    vector<int> b{2, 4, 6, 8};
    auto iter = a.begin() + 3;
    cout << *iter << endl;
    swap(a, b);
    cout << *iter << endl;
}