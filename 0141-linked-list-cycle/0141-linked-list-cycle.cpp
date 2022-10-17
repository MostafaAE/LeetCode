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
    * Approach: 
    * Robert W. Floyd's tortoise and hare algorithm: 
    * move two pointers at different speeds through the sequence of values, if they met at some point
    * then there is a cycle. otherwise, fast will reach the end on the list (null)
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    bool hasCycle(ListNode *head) 
    {
        if(!head)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        // O(n)
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            // if there is a cycle then slow and fast pointers will meet at some point
            if(slow == fast)
                return true;
        }
        return false;
    }
};