#include "node.h"
#include <iostream>
#include "picosha2.h"
using namespace std;
class tree 
{
private:
    string merkleRoot;
    int makeBinary(vector<node*> &node_vector);
    void printTreeLevel(vector<node*> v);
    vector<vector<node*>> base; //里面存的是一个个节点列表
public:
    tree();
    void buildTree();
    string getMerkleRoot();
    void buildBaseLeafes(vector<string> base_leafs);
    void iterateUp(int element);
    int verify(string hash);
    virtual ~tree();
};

tree::tree() {}

int tree::makeBinary(vector<node*> &node_vector) 
{
    int vectSize = node_vector.size();
    if ((vectSize % 2) != 0) //如果元素个数为奇数
    {
        node_vector.push_back(node_vector.end()[-1]); //push_back最后一个元素 即.end()-1 
        vectSize++;
    }
    return vectSize;
}

void tree::buildTree() 
{
    do 
    {
        vector<node*> new_nodes;
        makeBinary(base.end()[-1]); //传入尾元素 即一个节点列表

        for (int i = 0; i < base.end()[-1].size(); i += 2) 
        {
            node* new_parent = new node;
            //设置父亲节点 传入最后一个元素 即一个节点列表的第i和i+1个
            base.end()[-1][i]->setParent(new_parent);
            base.end()[-1][i+1]->setParent(new_parent);

            //设置哈希值
            new_parent->setHash(base.end()[-1][i]->getHash() + base.end()[-1][i+1]->getHash());
            //设置左右孩子节点
            new_parent->setChildren(base.end()[-1][i], base.end()[-1][i+1]);
            //将new_parent压入new_nodes
            new_nodes.push_back(new_parent);

            cout << "Hash togther: " << base.end()[-1][i]->getHash() << \
            " and " << base.end()[-1][i+1]->getHash() << " attached: " << \
            &new_parent << endl;
        }

        // printTreelevel(new_nodes);

        //将new_nodes压入base
        base.push_back(new_nodes);

        cout << "Hashed level with: " << base.end()[-1].size() << '\n';
    }
    while (base.end()[-1].size() > 1);

    merkleRoot = base.end()[-1][0]->getHash();

    cout << "Merkle Root is : " << merkleRoot << endl << endl;
}
void tree::printTreeLevel(vector<node*> v) //打印每个节点的哈希值
{
  cout << endl;

  for (node* el : v) 
  {
    cout << el->getHash() << endl;
  }
}
void tree::buildBaseLeafes(vector<string> base_leafs) //建立叶子节点列表
{
    vector<node*> new_nodes;
    
    cout << "Root leafs are : " << '\n';

    //给每一个字符串创建对应节点，并通过这个字符串设置哈希值
    for (auto leaf : base_leafs) 
    {
        node* new_node = new node;
        new_node->setHash(leaf);
        cout << new_node->getHash() << '\n';

        new_nodes.push_back(new_node);
    }

    base.push_back(new_nodes);
    cout << '\n';
}

int tree::verify(string hash) 
{
    node* el_node = nullptr;
    string act_hash = hash;

    //如果base[0]中有一个节点的hash值和其相等
    for (int i = 0; i < base[0].size(); i++)  
    {
        if (base[0][i]->getHash() == hash) 
        {
            el_node = base[0][i]; //指向该节点
        }
    }

    cout << "Hash verify: " << act_hash << '\n';

    do 
    {

        if(el_node->checkDir() == 0)
        {
            act_hash = picosha2::hash256_hex_string(act_hash + el_node->getSibling()->getHash());
        }
        else
        {
            act_hash = picosha2::hash256_hex_string(el_node->getSibling()->getHash() + act_hash);
        }

        std::cout << "Hash verify: " << act_hash << '\n';

        el_node = el_node->getParent();
  }
  while ((el_node->getParent()) != NULL);

  return act_hash == merkleRoot ? 1 : 0;
}
t