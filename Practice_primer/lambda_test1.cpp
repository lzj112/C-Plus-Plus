#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void biggers(vector<string>& words,vector<string>::size_type sz,
             ostream &os = cout, char c= 'c')
{
    //os隐式捕获　引用捕获方式；c显示捕获　值捕获方式
    for_each(words.begin(), words.end(), 
            [&, c](const string& s){os << s << c; });
    //os显示捕获，引用捕获方式；c隐式捕获，值捕获方式
    for_each(words.begin(), words.end(),
             [=, &os](const string& s) {os << s << c; });
}

/*混合使用隐式捕获和显示捕获时，捕获列表中第一个元素必须是一个＆或一个＝，此符号指定了默认捕获方式，而且，显示捕获方式
必须和隐式捕获方式不同。*/