#pragma once 


namespace hello_class 
{

class Hello 
{
public:
    Hello()
    {}
    Hello(int v);
    ~Hello() 
    {}
    void print();
private:
    int val;
};

}
