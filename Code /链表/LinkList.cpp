#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode *&head)
{

    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *mid = slow->next;
    slow->next = nullptr;
    ListNode *cur = mid, *pre = nullptr;
    while (cur)
    {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    while (head && pre)
    {

        cout << "test head: " << head << " val: " << head->val << endl;
        ListNode *temp1 = head->next;
        ListNode *temp2 = pre->next;
        pre->next = head->next;
        head->next = pre;
        head = temp1;
        
        pre = temp2;
    }
}
int main()
{

    ListNode *head = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);

    head->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = nullptr;

    

    // 找第n个节点
    ListNode *fast = head;
    int i = 0;
    for (i = 0; i < 2; i++)
    {
        fast = fast->next;
    }

    cout << "i --> " << i << " n --> " << fast->val << endl;

    // 找链表的中间节点
    fast = head;
    ListNode *slow = head;
    // 如果链表个数为奇数，那么直接找到了中间结点，如果是偶数则是中间结点的前一个
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "mid --> " << slow->val << endl;


    ListNode *cur = head;
    while (cur)
    {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << endl;

    cout << "head->val: " << head << endl;

    reorderList(head);

    cur = head;
    while (cur)
    {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << endl;

    cout << "head->val: " << head << endl;

    return 0;
}