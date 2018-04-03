#include <iostream>
using namespace std;
class tmp 
{
private:
    mutable int count; //声明一个可变的变量，
public:
    tmp()
    {
        count = 0;
    }
    void change() const;
    void show()
    {
        cout << count << endl;
    }
};
void tmp :: change() const //即使在const函数中 也可以改变
{
    count++;
}
int main()
{
    tmp a;
    for (int i = 0; i < 10; i++)
    {
        a.change();
    }
    a.show();
    return 0;
}