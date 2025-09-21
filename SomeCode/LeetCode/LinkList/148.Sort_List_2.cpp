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

ListNode *tail (ListNode *l)
{
    ListNode *work=l;
    while(work->next!=nullptr){
        work=work->next;
    }
    return work;
}

ListNode *getMid(ListNode *head)
{
    ListNode *slow = head,*fast=head;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode *merge(ListNode *l1, ListNode *l2, ListNode *l3)
{
    ListNode *dummy = new ListNode (0);
    ListNode *work =dummy;
    if(l1 != nullptr)
    {
        work->next = l1;
        work = tail(l1);
    }
    if(l2 != nullptr){
        work->next = l2;
        work = tail(l2);
    }
    if(l3 != nullptr)
    {
        work->next = l3;
    }
    return dummy->next;
    
}


// 利用链表做快速排序
ListNode* sortList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)
        return head;
    
    ListNode *mid = getMid(head);
    int midval = mid->val;
    ListNode *leftdummy = new ListNode(0);
    ListNode *middummy = new ListNode(0);
    ListNode * rightdummy = new ListNode(0);
    
    ListNode *leftwork = leftdummy, *midwork = middummy, *rightwork = rightdummy;
    ListNode *work = head;
    while(work != nullptr)
    {
        if(work->val<midval)
        {
            leftwork->next = work;
            leftwork = work;
        }
        else if(work->val == midval)
        {
            midwork->next = work;
            midwork = work;
        }
        else
        {
            rightwork->next = work;
            rightwork = work;
        }
        work = work->next;
    }
    leftwork->next=nullptr;  
    midwork->next=nullptr;  
    rightwork->next=nullptr;
    
    ListNode *left= sortList(leftdummy->next);
    ListNode *right = sortList (rightdummy->next);
    
    return merge(left,middummy->next,right);
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