#include<iostream>
using namespace std;
/*void prin( int (&a)[])
{
    for (auto i : a)
    {
        cout << i << endl;
    }
}*/
void prin(int a[])
{
    for ( int i : a)
    {
        cout << i << endl;
    }
}
int main()
{
 int a[]={1, 2, 3, 4, 5};
 prin(a);
 return 0 ;
}