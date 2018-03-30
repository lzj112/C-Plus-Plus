#include <iostream>
using namespace std;
class tmp 
{
private:
    mutable int count;
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
void tmp :: change() const
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