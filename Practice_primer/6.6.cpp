#include<iostream>
#include<string>
using namespace std;

int sumLength(const string &, const string &)
{
    cout << "here is sumlength\n";
}

int largerLength(const string &, const string &)
{
    cout << "here is largerlength\n";
}
decltype(sumLength) *getfun(const string &)
{
    cout << "here is getfun\n";
    //cout << &a  << "  add "<< endl;
    //  return &;
}
int main()
{
    // getfun("abc");
    cout << getfun("abc") << endl;
}
 