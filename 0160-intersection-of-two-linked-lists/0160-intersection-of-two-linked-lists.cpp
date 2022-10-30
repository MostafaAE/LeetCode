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
        ListNode *curA = headA, *curB = headB;
        
        while(curA != curB)
        {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        
        return curA;
        
    }
};