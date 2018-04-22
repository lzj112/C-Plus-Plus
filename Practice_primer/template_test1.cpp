/*************************************************************************
	> File Name: template_test1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年04月17日 星期二 21时16分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
template<class T>
void tmp(T a) 
{
    cout << "here is template " << a << endl;
}
void tmp(string a) 
{
    cout << "here is not template " << a << endl;
}
int main() 
{
    tmp(2);
    string a("i love u");
    tmp(a);
}
