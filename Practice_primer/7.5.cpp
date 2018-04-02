#include <iostream>
#include <string>
using namespace std;
class tmp 
{
private:
    int a;
    string s;
public:
    tmp()
    {

    }
    void show(const string &str)
    {
        cout << str << endl;
    }
};
int main()
{
    string ctr = "i love u!";
    tmp a;
    tmp b;
    b.show("i love u!!");
    tmp c;
    c.show(string("i love u!!"));

}