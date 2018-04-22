#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void erase(vector<string>& tmp);
int main() 
{
    vector<string> a{string("red"), string("red"), string("slow"), string("red"), string("slow")};
    erase(a);
    for (string x : a) 
    {
        cout << x << endl;
    }
    return 0;
}
void erase(vector<string>& a) 
{
    sort(a.begin(), a.end());
    auto q = unique(a.begin(), a.end()); 
    //unique会将重复的单词覆盖　他不真正删除元素，
    //返回值为一个指向最后一个不重复元素之后的迭代器，此位置之后的额元素依然在，但我们不知道他的值是什么
    a.erase(q, a.end());
    //真正删除无用元素
    
}