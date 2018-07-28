#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * findTheLastKNode(ListNode *phead, int k)
{
    if (phead == nullptr || k <= 0)
        return nullptr;

    ListNode *p  = phead;
    int count = 0;
    while(p)
    {
        count ++;
        p = p->next;
    }

    if (count < k)
        return nullptr;

    p = phead;
    for(int i = 0; i < k-1; i++)
    {
        p = p->next;
    }

    ListNode *q = phead;

    while(p->next)
    {
        p = p->next;
        q = q->next;
    }

    return q;
}

int main()
{



    cout << "hello word" << endl;
    return 0;
}
