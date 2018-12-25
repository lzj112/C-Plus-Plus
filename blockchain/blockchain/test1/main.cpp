#include <iostream>
#include <vector>
#include "block.h"
#include "chain.h"
#include "md5.h"
using namespace std;

int main() 
{
    Chain BlockChain;
    int index;
    int flag = 5;
    string str, prehash;
    while (flag--) //EOF结束
    {
        auto it = BlockChain.BlockChainTmp.end();
        index = it[-1].Index + 1;
        prehash = it[-1].Hash;
        Block t(index, prehash);
        t.Input();
        BlockChain.AddBlock(t);
    }
    BlockChain.Output();
}