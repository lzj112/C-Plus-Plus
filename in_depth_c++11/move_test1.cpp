#include <iostream>
#include <string>
using namespace std;

void func(string&& str) 
{
    cout << "here is func : " << str << endl;
}

int main() 
{
    
    {
        string a = "here is a test";
        string b = move(a);
        cout << "a : " << a << endl;
        cout << "b : " << b << endl << endl;
    }
    
    {
        string a = "here is a test";
        string b(move(a));
        cout << "a : " << a << endl;
        cout << "b : " << b << endl << endl;
    } 
}