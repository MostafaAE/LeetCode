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
    * Space Complexity : O(n+m)
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        unordered_set<ListNode *> s;
        
        while(headA || headB)
        {
            if(headA)
            {
                if(!s.insert(headA).second)
                    return headA;
                headA = headA->next;
            }
            if(headB)
            {
                if (!s.insert(headB).second)
                    return headB;
                headB = headB->next;
            }
        }
        
        return nullptr;
        
    }
};