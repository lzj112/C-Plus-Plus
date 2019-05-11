
#include <iostream>
#include "person.h"

Person::Person(int v)
    : val(v) 
{}

void Person::print() 
{
    std::cout << val << std::endl;
}

