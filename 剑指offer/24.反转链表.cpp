#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
    if (head == nullptr)
        return head;

    ListNode *pReverseHead = nullptr;
    ListNode *pre = nullptr;
    ListNode *pNode = head;
    ListNode *pNext = nullptr;

    while(pNode)
    {
        pNext = pNode->next;
        if (pNext == nullptr)
            pReverseHead = pNode;

        pNode->next = pre;
        pre = pNode;
        pNode = pNext;
    }
    return pReverseHead;
}

int main()
{



    cout << "hello world" << endl;
    return 0;
}