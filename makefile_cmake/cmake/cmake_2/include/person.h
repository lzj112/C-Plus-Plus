#ifndef PERSON_H_
#define PERSON_H_

class Person 
{
public:
    Person(int v);
    ~Person()
    {}
    void print();
private:
    int val;
};

#endif