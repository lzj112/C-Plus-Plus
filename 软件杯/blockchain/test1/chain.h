#include <iostream>
#include "block.h"
#include <string>
#include <vector>
using namespace std;

class Chain 
{
    vector<Block> BlockChainTmp;
public:
    Chain(); //添加创世区块
    ~Chain();
    void AddBlock(Block t); //添加新区快
    void Output(); //遍历输出链
};
