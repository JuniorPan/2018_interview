#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {
	}
};


ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        int num1 = 0;
        int num2 = 0;

        ListNode *p = pHead1, *q = pHead2;
        while(p)
        {
            p = p->next;
            num1 ++;
        }
        while(q)
        {
            q = q->next;
            num2 ++;
        }
        
        ListNode *pLong = pHead1;
        ListNode *pShort  = pHead2;
        int k = num1 - num2;
        
        if (num1 < num2)
        {
            ListNode *pLong = pHead2;
            ListNode *pShort  = pHead1;
            k = num2 - num1;
        }
        
        
        for(int i = 0; i < k; i++)
        {
            pLong = pLong->next;
        }
        
        while (pLong && pShort && (pLong != pShort))
        {
            pLong = pLong->next;
            pShort = pShort->next;
        }
        
        return pLong;
    }


int main()
{
    
    
    
    return 0;
}