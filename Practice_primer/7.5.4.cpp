#include <iostream>
#include <string>
using namespace std;
class Student
{
    string name;
    int number;
public:
    Student(const string &str, int n = 1) : name(str), number(n) {} 
    Student() {}
    void Print(const Student &s); //期待的是Student类的参数
};
void Student::Print(const Student &s)
{
    if (s.name == name) 
    {
        cout << "same person" << endl;
    }
    else 
    {
        cout << "different" << endl;
    }
}
int main()
{
    Student a("lzj");
    Student b("lb");

    cout << "a == b ? : " <<endl;
    a.Print(b);

    cout << "a == a ? : " << endl;
    a.Print(string("lzj")); //这里传递的是string类
    
    // cout << "a == a ? : " << a.Print("lzj") << endl;
    return 0;
}