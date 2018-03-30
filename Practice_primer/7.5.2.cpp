//构造函数初始化之列表只能说明用于初始化成员的值，而不限定初始化的具体执行顺序
// 成员的初始化顺序与他们在类中定义中出现的顺序一致
#include <iostream>
class tmp 
{
private:
    int i;
    int j;
public:
    tmp(int val) : j(val), i(j) {}
    void show()
    {
        std::cout << "i == " << i << " j == " << j << std::endl;
    }
};
int main()
{
    tmp s(1);
    s.show();
    return 0;
}