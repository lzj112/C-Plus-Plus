#include "hello.h"

namespace hello_class
{

#include <iostream>

Hello::Hello(int v)
    : val(v)
{}

void Hello::print() 
{
    std::cout << val << std::endl;    
}

}