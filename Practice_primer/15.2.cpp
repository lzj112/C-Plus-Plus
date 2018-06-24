#include <iostream>
using namespace std;
template<class T, class Q>
bool fun(const char p1[T], const char p2[Q]) 
{
    return strcmp(p1, p2);
}
int main() 
{
    char* str = "i still love u!";
    char ctr[] = "but she does not";
    cout << fun(str, ctr) << endl;
}