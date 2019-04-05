#include <set>
#include <map>
#include <vector>
#include <memory>
#include <utility>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main()
{

    auto ptr1 = make_shared<int> (5);
    auto ptr2 = ptr1;   
    unordered_set<shared_ptr<int> > s1;
    s1.insert(ptr1);
    s1.insert(ptr2);
    cout << s1.size() << endl;
    
    int* ptr_1 = new int(10);
    int* ptr_2 = ptr_1;
    unordered_set<int *> s2;
    s2.insert(ptr_1);
    s2.insert(ptr_2);
    cout << s2.size() << endl;
}