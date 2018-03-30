
//初始化const或者引用类型的数据成员的唯一机会就是通过构造函数初始值
#include <iostream>
class a
{
private:
    int i1;
    const int &i2;
    int &i3;
    const int i4;
public:
    a(int tmp) : i2(tmp), i3(tmp), i4(tmp) {}
};
int main()
{
    a aa(1);
}
