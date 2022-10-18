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
    * Iterate over the linkedlist, if the current node value == next node value, then
    * delete the next node
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head)
            return head;
        
        ListNode *cur = head;
        
        while(cur && cur->next)
        {
            if(cur->val == cur->next->val)
            {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else
                cur = cur->next;
        }
        
        return head;
    }
};