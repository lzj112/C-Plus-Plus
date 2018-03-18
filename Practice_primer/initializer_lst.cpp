#include<iostream>
// #include<initializer_list>
#include<vector>
using namespace std;
template < typename T>
void fun(initializer_list <T> lst)
{
    cout << "lst.size==" << lst.size() << endl;
    auto begin = lst.begin(), end = lst.end();
    T sum;
    for (; begin != end; begin++)
    {
        sum += *begin;
    }
    cout << sum << endl;
}
int main()
{
    string tmp[] = {"aaaa", "bbbb", "cccc", "dddd"};
    vector < string > str(&tmp[0], &tmp[4]);
    cout << str[0] << endl
         << str[1] << endl
         << str[2] << endl;
    fun({str[0], str[1], str[2]});
    // fun({"aaa", "bbb", "ccc"});   这样传的是const char *
}