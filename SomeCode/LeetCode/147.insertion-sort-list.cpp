/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *fakeHead = new ListNode(-1);

        ListNode *p = nullptr;
        fakeHead->next = nullptr;
        while (head)
        {
            p = head->next;
            ListNode *q = fakeHead;

            if (fakeHead->next == nullptr)
            {
                fakeHead->next = head;
                head->next = nullptr;
                head = p;
            }
            else
            {
                while (q->next && q->next->val < head->val)
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
};
// @lc code=end
