/*************************************************************************
	> File Name: accunmlate.cpp
	> Author: 吕白
	> Purpose:
	> Created Time: 2018年03月08日 星期四 21时02分43秒
 ************************************************************************/

#include<iostream>
#include<numeric>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};

    int sum1 = accumulate( begin( arr ), end( arr ), 0 );
    
    vector < int > a( &arr[0], &arr[9] );
    int sum2 = accumulate( a.begin(), a.end(), 0 );
    
    cout << sum1  << ' ' << sum2 << endl;

    cout << "aaa\n";
    for ( int x : a ) 
    {
        cout << x << endl;
    }
}

/*
accumulate(first,last, init);
first，last可以是数字也可以是字符串，将把init 和从 first 到last 指向的值进行累加，并返回累加得到的和
*/
