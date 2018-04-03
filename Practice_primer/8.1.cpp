#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "before " << cin.fail() << endl;
    cin >> a; //输入char类型 发生错误
    cout << "after " << cin.fail() << endl;

    cin.clear();//复位
    cout << "after clear " << cin.fail() << endl;
    //char还在缓冲区
    cin >> a;
    cout << "again " << cin.fail() << endl;

    cin.clear();
    cin.get(); //拿出缓冲区的一个字符
    cin >> a;
    cout <<"a == " << a << endl;

}