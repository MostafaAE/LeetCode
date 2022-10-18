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
    * Iterate on the linkedlist, and connect each node's next with the previous
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode *cur = head, *prev = nullptr;
        
        while(cur)
        {
            // last node;
            if(!cur->next)
                head = cur;
            
            ListNode *next = cur->next;

            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return head;
        
    }
};