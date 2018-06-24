#include <iostream>
class a 
{
public:
    // a() = delete;
    ~a();
};
int main() 
{
    a aa;
    a* p;
    delete p;
}