#include <iostream>
#include "tree.h"
#include "picosha2.h"
using namespace std;

int main()
{
    string check_str = "";

    cout << "Enter Merkle leafes: " << endl;
    //叶子节点为string类
    vector<string> v;

    //输入叶子节点
    while (1) 
    {
        string str;
        cin >> str;
        if (str != ";") 
        {
            //存入v
            v.push_back(str);
        }
        else 
        {
            break;
        }
    }

    cout << "Enter leaf to verify: " << endl;
    //输入想验证的叶子节点
    cin >> check_str;
    check_str = picosha2::hash256_hex_string(check_str);

    tree ntree;
    ntree.buildBaseLeafes(v);
    ntree.buildTree();

    cout << "Check if: " << check_str << " is contained in tree " << endl;

    //验证有无这个节点 树有无改变
    if (ntree.verify(check_str)) 
    {
        cout << "All clear\n";
    }
    else 
    {
        cout << "something is wrong\n";
    }
    return 0;
}