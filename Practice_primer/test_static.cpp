#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {
        ++count;
    }
    ~MyClass() {
        --count;
    }
    static int getCount() {
        return count;
    }
private:
    static int count;
};
int MyClass::count = 0;
int main() {
    MyClass obj;
    cout << obj.getCount();
    MyClass obj2;
    cout << MyClass::getCount();
    cout << obj2.getCount();
    return 0;
}