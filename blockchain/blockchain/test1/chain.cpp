#include "chain.h" 


Chain::Chain() 
{
    Block tmp;
    tmp.PreHash = "";
    tmp.Data = "";
    tmp.Index = 0;
    tmp.TimeStamp = tmp.GetTime();
    tmp.Hash = tmp.GetHash();
    BlockChainTmp.push_back(tmp);
}
Chain::~Chain() 
{

}
void Chain::AddBlock(Block t) 
{
    BlockChainTmp.push_back(t);
}

void Chain::Output() 
{
    for (auto x : BlockChainTmp) 
    {
        cout << "-------------------------------------------------------------\n"
             << "There is the " << x.Index << " block : \n"
             << "his PreHah : " << x.PreHash << endl
             << "his TimeStamp : " << x.TimeStamp << endl
             << "his Hash : " << x.Hash << endl
             << "his Dta : " << x.Data << endl;
    }
}
