#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <iostream>
using namespace std;

struct BlockHead //区块头
{
    string PreHash; //前一区块哈希
    //string MrekleTreeRoot; 梅克尔树根哈希
    string Data; //简化操作，Data表示数据，本应该是梅克尔树根哈希值
    string TimeStamp; //时间戳
    int Index; //索引
}; 
class Block : public BlockHead
{
public:
    //int size; //区块大小
    //int Separator = 0xD9B4BEF9; //分隔符
    string Hash; //本区块区块头的哈希值
    Block() {}
    Block(int index, string prehash); 
    string GetHash(); //计算本区块哈希值
    void Input(); // 输入数据
    string GetTime(); //得到当前时间戳
};
#endif
