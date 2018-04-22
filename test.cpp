#include <iostream>
using namespace std;
class a 
{
public:
    void show() {}
};
void a::show() 
{
    cout << "here\n";
}
int main() 
{
    a aa;
    aa.show();
}