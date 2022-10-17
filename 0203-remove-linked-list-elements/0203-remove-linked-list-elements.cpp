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
    * Iterate over the linkedlist if the current node value == target, then
    * re-link the previous node with the next node
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *cur = head, *prev = nullptr;
        
        while(cur)
        {
            if(cur->val == val)
            {
                ListNode *temp = cur;
                
                // if target is first node, move the head pointer
                if(!prev)
                    head = head->next;
                else
                    prev->next = cur->next;
                
                cur = cur->next;
                
                delete temp;
            }
            else
                prev = cur, cur = cur->next;
            
            
        }
        
        return head;
    }
};