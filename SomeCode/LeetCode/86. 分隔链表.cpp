
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (!head)
            return nullptr;
        // small_head 用来存放小于 x 的节点
        // large_head 用来存放大于等于 x 的节点
        ListNode *small_head = new ListNode(-1);
        ListNode *large_head = new ListNode(-1);

        ListNode *small = small_head; // small 链表的尾指针
        ListNode *large = large_head; // large 链表的尾指针

        // 遍历原链表
        while (head)
        {
            if (head->val < x)
            {
                small->next = head;  // 挂到 small 链表
                small = small->next; // 更新 small 尾指针
            }
            else
            {
                large->next = head;  // 挂到 large 链表
                large = large->next; // 更新 large 尾指针
            }
            head = head->next; // 遍历下一个节点
        }
        // 拼接两个链表：small 的尾巴指向 large_head->next
        small->next = large_head->next;
        // large 的尾巴必须断开，否则可能出现环
        large->next = nullptr;
        return small_head->next;
    }
};