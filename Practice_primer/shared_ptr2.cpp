#include <iostream>
#include <memory>
using namespace std;
void change(shared_ptr<int> p) 
{
    cout << "here is change\n";
}
int main() 
{
    int n = 89789;
    int* x = new int(n);
    cout << "before " << *x << endl;
    change(shared_ptr<int> (x));
    cout << "after " << *x << endl;
}
