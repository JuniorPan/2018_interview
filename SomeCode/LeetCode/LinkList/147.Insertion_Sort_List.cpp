#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



ListNode* insertionSortList(ListNode* head)
{
    if (head == nullptr)
        return head;

    ListNode *fakeHead = new ListNode(-1);
    
    ListNode *p = nullptr;
    fakeHead->next = nullptr;
    while(head)
    {
        p = head->next;
        ListNode *q = fakeHead;
        if (fakeHead->next == nullptr)
        {
            fakeHead->next = head;
            head->next = nullptr; // todo 这个地方注意要置为空
            head = p;
        }
        else
        {
            while(q->next && q->next->val < head->val)
            {
                q = q->next;
            }
            head->next = q->next;
            q->next = head;
            
            head = p;
        }  
    }
    
    return fakeHead->next;
}


int main()
 {


     return 0;
 }