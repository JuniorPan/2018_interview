/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return nullptr;
        
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        
        while(slow != fast)
        {
            if (fast->next == nullptr || fast->next->next == nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};