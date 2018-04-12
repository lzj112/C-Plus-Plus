#include <iostream>
#include <vector>
using namespace std;
class tmp 
{
    int a;
public:
    tmp(int a) {this->a = a;}
    ~tmp() {cout << "here is ~tmp()" << endl;}
};
int main() 
{
    /*vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int>& b = a;
    cout << b[3] << endl;
    a.push_back(123);
    b.push_back(222222222222);
    cout << b[6] << endl;
    cout << a[7] << endl;
    cout << b.size() << endl;*/
    vector<tmp> a;
    a.push_back(tmp(2)); //存放一个临时变量
    cout << "aaaaaaaa\n"; //证明stl容器都是赋值元素进去
}