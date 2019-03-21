#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <memory>
#include <string>
#include <algorithm>
using namespace std;

struct listNode
{
    listNode(int v) : val(v) {}
    int val;
    listNode* next;
};

listNode* func(listNode* root) 
{
    if (root == nullptr)
        return nullptr;
    listNode* preNode = nullptr;
    listNode* nextNode = root->next;

    while (root != nullptr) 
    {
        root->next = preNode;
        preNode = root;
        root = nextNode;
        if (nextNode != nullptr)
            nextNode = nextNode->next;
    }
    return preNode;
}

int main() 
{
    listNode* root = new listNode(1);
    root->next = new listNode(2);
    root->next->next = new listNode(3);

    listNode* r = func(root);

    while (r != nullptr)
    {
        cout << r->val << endl;
        r = r->next;
    }
}