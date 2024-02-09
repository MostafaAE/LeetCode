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
    * Get the size on the linkedlist, then remove the nth node from the end.
    * We can also solve it in one pass by storing all the nodes in a vector then remove the target node but will be O(n) memory.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) 
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = new ListNode(0, head), *cur = head;
        int size{1};
        
        while(cur)
            size++, cur = cur->next;
        
        int steps = size - n - 1;
        cur = dummy;
        while(steps--)
            cur = cur->next;
        
        cur->next = cur->next->next;
        return dummy->next;
            
    }
};