/*************************************************************************
	> File Name: map_insert_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年05月01日 星期二 13时30分15秒
 ************************************************************************/

#include <map>
#include <string>
#include <iostream>
using namespace std;
int main() 
{
    map<string, int> a{{"asasasasas", 6}};
    map<string, int> b {{"asasasasa", 3}, make_pair("abcd", 1), {"aaaaa", 2}};
    auto c = a.insert({"abcd", 2});
    auto d = b.insert(make_pair("abcd", 1));
    cout << c.first->first << endl;
    cout << d.first->first << endl;
}
