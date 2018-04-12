#include <list>
#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    }
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode l3(0);
    ListNode *p = &l3;
    int flag = 0, tmp = 0;
    ListNode *p1 = l1, *p2 = l2;
    while (p1 || p2 || flag) 
    {   
        tmp = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + flag;
        flag = tmp / 10;
        p->next = new ListNode(tmp%10);
        p = p->next;
        p1 = p1 ? p1->next : p1;
        p2 = p2 ? p2->next : p2;
    }
    return l3.next;
}
