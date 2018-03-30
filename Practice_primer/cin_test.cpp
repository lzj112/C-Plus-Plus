#include <iostream>
using namespace std;
int main()
{
    int a, b;
    char c, d;
    cout << "cin.fail() == " << cin.fail() << endl;
    cin >> a;
    cout << "1  " << cin.fail() << endl;
    cin.clear();
    cin.get();
    cin >> b;
    cout << "2  " << cin.fail() << endl;
    return 0;
}