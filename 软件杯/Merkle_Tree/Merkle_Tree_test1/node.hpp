#include <iostream>
#include <sstream>
#include "picosha2.h"
#include <string>
#include <vector>
using namespace std;

class node 
{
private:
    string hash_str;
    node *parent;
    node *children[2];
public:
    node();
    node* getParent();
    void setChildren(node *children_l, node *children_r);
    node *getChildren(int index);
    void setParent(node *parent);
    string getHash();
    int checkDir();
    node *getSibling();
    void setHash(string hash_str);
    virtual ~node();
};
node::node() 
{
    parent = nullptr;
    children[0] = nullptr;
    children[1] = nullptr;
}

//设置哈希值
void node::setHash(string hash_str) 
{
    this->hash_str = picosha2::hash256_hex_string(hash_str);
}
node* node::getParent() 
{
    return parent;
}
void node::setParent(node *parent) 
{
    this->parent = parent;
}
void node::setChildren(node *children_l, node *children_r) 
{
    children[0] = children_l;
    children[1] = children_r;
} 
node* node::getSibling() //是左孩子得到右孩子，是右孩子得到左孩子
{
    //得到该节点的父节点
    node* parent = getParent();

    //判断父节点的左孩子和本节点是否相同
    //相同返回右孩子，不同返回左孩子
    return parent->getChildren(0) == this ? parent->getChildren(1) : parent->getChildren(0);
}
node* node::getChildren(int index) 
{
    return index <= 1 ? children[index] : nullptr;
}
string node::getHash() 
{
    return hash_str;
}
int node::checkDir() 
{
    //如果其父节点的左孩子是该节点 返回0 否则则返回1
    return parent->getChildren(0) == this ? 0 : 1;
}

node::~node() {}
