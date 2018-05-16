#include "block.h"
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using namespace std;

Block::Block(int index, string prehash) 
{
    PreHash = prehash;
    Data = Input();
    Index = index;
    TimeStamp = GetTime();
    Hash = GetHash();
}
string Block::GetHash() 
{

}
string Block::Input() 
{
    string str;
    cout << "输入数据 ： \n";
    cin >> str;
    return str; 
}
string Block::GetTime() 
{
    time_t t;
    tm *local;
    char buf[256];
    t = time( nullptr );
    local = localtime( &t );
    strftime( buf, 64, "%Y-%m-%d %H:%M:%S",local );     //转换　buf里存时间
    string time(buf);
    // cout << buf << endl;
    return time;

}
