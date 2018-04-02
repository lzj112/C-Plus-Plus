// 隐式的类类型转换
#include <iostream>
#include <string>
using namespace std;
class Fruit 
{
    string name;
    string colour;
public:
    bool isSame(const Fruit &otherFruit) //期待的形参是另一个Fruit类对象
    {
        return name == otherFruit.name;
    }
    void print()
    {
        cout << colour << ' ' << name << endl;
    }
    Fruit(const string &nst, const string &cst = "green") : name(nst), colour(cst) {}
    Fruit() {}
};
int main()
{
    Fruit apple("apple");
    Fruit orangle("orangle");
    cout << "apple = orangle ? : " << apple.isSame(orangle) << endl; // 没有问题 不同
    cout << "apple = apple ? : " << apple.isSame(string("apple")) << endl; //用一个string作为形参
    return 0;
}
    