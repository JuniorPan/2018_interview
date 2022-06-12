#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
        
    if (l1 == NULL && l2 == NULL)
        return NULL;
    
    ListNode *pHead = new ListNode(-1);
    ListNode *tail = pHead;
    
    ListNode *p = l1;
    ListNode *q = l2;
    
    while (p && q)
    {
        if (p && (!q || p->val < q->val))
        {
            tail->next = p;
            p = p->next;
            
        }
        else
        {
            tail->next = q;
            q = q->next;
        }
        tail= tail->next;
    }
    
    tail->next = p ? p : q;
    return pHead->next;
}

int main()
{



    cout << "hello world" << endl;
    return 0;
}