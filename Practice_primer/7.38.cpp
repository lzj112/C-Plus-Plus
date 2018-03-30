// 提供cin作为接受istream参数的构造函数　
#include <iostream>
#include <istream>
#include <string>
using namespace std;
class tmp 
{
private:
    string str;
public:
    tmp(istream &is)
    {
        is >> str;
    }
    void show()
    {
        cout << str << endl;
    }
};
int main()
{
    tmp str(cin);
    str.show();
    return 0;
}