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
    * then there is a cycle. otherwise, the fast pointer will reach the end of the list (null)
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    bool hasCycle(ListNode *head) 
    {
        ListNode *slow{head}, *fast{head};
        
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