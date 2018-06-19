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

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *fakeHead = new ListNode(-1);
    ListNode *p = fakeHead;
    
    while(l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            p->next = l1;
            l1 = l1->next;   
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1 != nullptr)
    {
        p->next = l1;
    }
    if (l2 != nullptr)
    {
        p->next = l2;
    }
    
    return fakeHead->next;
}

//O(nlogn)对链表排序 归并和递归的方式
ListNode* sortList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)
        return head;
                                        
    ListNode * fast = head->next, *slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    fast = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(fast));
}
    
ListNode *createListByArray(int *A, int n)
{
    ListNode *head = new ListNode(A[0]);
    ListNode *p = head;
    for(int i = 1;i < n;i++)
    {
        ListNode *node = new ListNode(A[i]);
        p->next = node;
        p = node;
    }
    return head;
}


void printLinkList(ListNode *head)
{
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

    
int main()
{
    int a[] = {2,34,4,5,43,6,3,56,7,43};
    int n = sizeof(a) / sizeof(a[0]);
    ListNode *head = createListByArray(a, n);
    printLinkList(head);

    sortList(head);
    printLinkList(head);

    return 0;
 }