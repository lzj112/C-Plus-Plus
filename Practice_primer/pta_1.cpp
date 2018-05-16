#include <iostream>
using namespace std;
class Vehicle

{

protected:

string NO;
public:

Vehicle(string n){

NO = n;

}

virtual int fee()=0;//计算应收费用

};

class Car : public Vehicle 
{
    int guest, weight;
public:
    Car(string str, int a, int b) : Vehicle(str), guest(a), weight(b) {

    }
    int fee() 
    {
        return (guest*8 + weight*2 );
    }
};
class Truck : public Vehicle 
{
    int guest, weight;
public:
    Truck(string str, int a, int b) :  Vehicle(str), guest(a), weight(b) {

    }
    int fee() 
    {
        return (weight * 5);
    }
};
class Bus : public Vehicle 
{
    int guest, weight;
public:
    Bus(string str, int a, int b) :  Vehicle(str), guest(a), weight(b) {
    }
    int fee() 
    {
        return guest * 3;
    }
};