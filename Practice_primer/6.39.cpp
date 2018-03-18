#include<iostream>
using namespace std;
void a(const string &a, const string &b)
{
    cout << "here is const\n";
}
void a(string &a, string &b)
{
    cout << "here is not const\n";
}
int main()
{
    string aa = "i ", b = "love u!";
    const string c = "but ", d = "she's not";
    a(aa, b);
    a(c, d);
}
// 传参时会区分const　但是如果只有第一个函数，会默认讲非const转为const