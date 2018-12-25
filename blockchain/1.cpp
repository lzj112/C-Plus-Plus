//c++先序构建二叉树
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//二叉树的结构体
typedef struct Btree 
{
    int val;
    struct Btree *left, *right;
} Btree;

//二叉树的类　包含着操作二叉树的各种方法
class Tree 
{
public:
    Btree *root;
    Btree *create_node(int level, string pos);
    void PreOrder(Btree *t); //先序遍历
    void InOrder(Btree *t); //中序遍历
    void PostOrder(Btree *t); //后序遍历

};

//用先序遍历的方法递归构造一颗二叉树
Btree* Tree::create_node(int level, string pos) 
{
    int data;
    Btree *node = new Btree;

    cout << "please enter data :lever" << level << " " << pos << endl;
    cin >> data;
    //若输入的数据为0，则该节点的子节点置为空
    if (data == 0) 
    {
        return nullptr;
    }
    node->val = data;

    /*create_node（）的    参数用于在给二叉树赋值时表明 
    现在赋值的是哪个结点*/   
    node->left = create_node(level+1,"left");  
    node->right= create_node(level+1,"right");             
    return node;  
}
void Tree::PreOrder(Btree *t)  
{  
    if(t)  
    {  
        cout<<t->val<<endl;;  
        PreOrder(t->left);  
        PreOrder(t->right);                
    }  
}   
  
void Tree::InOrder(Btree *t)  
{  
    if(t)  
    {  
        InOrder(t->left);  
        cout<<t->val<<endl;;  
        InOrder(t->right);  
    }  
}  
  
void Tree::PostOrder(Btree *t)  
{  
    if(t)  
    {  
        PostOrder(t->left);  
        PostOrder(t->right);  
        cout<<t->val<<endl;    
    }  
}  
  
int main()  
{  
    Tree tree;  
    tree.root = tree.create_node(1,"root");  
    cout<<"Pre"<<endl;  
    tree.PreOrder(tree.root);  
      
    cout<<"In"<<endl;  
    tree.InOrder(tree.root);  
      
    cout<<"Post"<<endl;  
    tree.PreOrder(tree.root);     
      
    return 0;  
}  