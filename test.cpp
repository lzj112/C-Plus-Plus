#include <set>
#include <map>
#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <typeinfo>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class test 
{
public:
    test(int aa) : a(aa)
    {}
private:
    int a;
};

int main() 
{
    test t(199);
    int* ptr = (int *)&t;
    cout << *ptr << endl;
}