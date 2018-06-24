#include <iostream>
#include <chrono>
#include <ratio>
using namespace std;

int main() 
{
    typedef chrono::duration<int, ratio<60*60*24>> days_type;
    chrono::time_point<chrono::system_clock, days_type> today = 
        chrono::time_point_cast<days_type>(chrono::system_clock::now());

    cout << today.time_since_epoch().count() << " days since epoch" << endl;
    return 0;

}