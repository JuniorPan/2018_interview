/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (36.22%)
 * Likes:    2004
 * Dislikes: 119
 * Total Accepted:    238.9K
 * Total Submissions: 645.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    /* 
    解法一: 
    1. 使用快慢指针来找到链表的中点，并将链表从中点处断开，形成两个独立的链表。
    2. 将第二个链翻转。
    3. 将第二个链表的元素间隔地插入第一个链表中。
    */
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr )
            return;
        
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr; // 端口链表
        ListNode *cur = mid;
        ListNode *pre = nullptr;
        // 逆序后半段链表
        while(cur)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        // 将逆序的后半段插入到前半段中
        while(head && pre)
        {
            ListNode *temp = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = temp;
            head = temp;
        }
    }

};
// @lc code=end
