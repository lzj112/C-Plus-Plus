#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    vector<int> tmp;
    for (int i = 0; i < 10; i++) 
    {
        tmp.push_back(i);
    }

    cout << *tmp.data() << endl;
}