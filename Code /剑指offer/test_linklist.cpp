#include <iostream>
using namespace std;



struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int main()
{

    ListNode *t1 = new ListNode(1);
    ListNode *t2 = new ListNode(2);
    ListNode *t3 = new ListNode(3);
    ListNode *t4 = new ListNode(4);
    ListNode *t5 = new ListNode(5);
    ListNode *t6 = new ListNode(6);
    ListNode *t7 = new ListNode(7);

    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = t5;
    t5->next = t6;
    t6->next = nullptr;
    // t6->next = t7;
    // t7->next = nullptr;

    // ListNode *fast = t1;
    // for(int i = 0; i < 3; i++)
    // {
    //     fast = fast->next;
    // }

    // cout << "fast: " << fast->val << endl;

    ListNode *fast = t1, *slow = t1;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout << "slow: " << slow->val << endl;

    return 0;


}