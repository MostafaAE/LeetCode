/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n+m)
    * Space Complexity : O(1)
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int countA{}, countB{};
        ListNode *curA = headA, *curB = headB;
        
        while(curA)
            countA++, curA = curA->next;
        
        while(curB)
            countB++, curB = curB->next;
        
        if(countA > countB)
            for(int i = 0 ; i < countA-countB ; i++)
                headA = headA->next;
        else
            for(int i = 0 ; i < countB-countA ; i++)
                headB = headB->next;
        
        while(headA && headB)
        {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return nullptr;
        
    }
};