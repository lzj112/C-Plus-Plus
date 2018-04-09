#include <iostream>
using namespace std;
class Animal 
{
public:
    int age;
    Animal(int a) {age = a;}
    int getAge() {return age;}
};
class Dog : public Animal 
{
public:
    string color;
    Dog(int a, string b) : Animal(a) {color = b;}
    void showInfor() {cout << "age:" << age << endl; cout << "color:" << color << endl;}
};