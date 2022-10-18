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
    * Iterate recursively on the linkedlist till you reach the last node,
    * then connect each node's next with the previous node while going back from the recursion
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    ListNode* reverseList(ListNode* cur, ListNode **dummy) 
    {
        if(!cur || !cur->next)
        {
            *dummy = cur;
            return cur;
        }
        
        ListNode *node = reverseList(cur->next, dummy);
        node->next = cur;
        cur->next = nullptr;
        return cur;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode *dummy;
        reverseList(head, &dummy);
        return dummy;
    }
};