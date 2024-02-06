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
class Solution {
public:
    /* 
    * Approach:
    * Partition the linked list into two lists (one contains elements less than x and the other greater than or equal to x) then merge them.
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *p1Head{}, *p1Tail{}, *p2Head{}, *p2Tail{}, *cur = head;
        
        while(cur)
        {   
            if(cur->val < x)
            {
                if(!p1Head)
                    p1Head = cur;
                else
                    p1Tail->next = cur;
                
                p1Tail = cur;
            }
            else
            {
                if(!p2Head)
                    p2Head = cur;
                else
                    p2Tail->next = cur;
                
                p2Tail = cur;
            }
            cur = cur->next;
        }
        
        if(p1Head)
            p1Tail->next = p2Head;
        if(p2Head)
            p2Tail->next = nullptr;
        
        if(!p1Head && p2Head)
            return p2Head;
        
        return p1Head;
    }
};