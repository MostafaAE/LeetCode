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
     * Use a slow and fast pointer to find the intersection point (where they meet), then move the head and the intersection 1 step until they meet.
     * Another solution: Use a hash table to check if a node is repeated.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *intersection = getIntersection(head);
        
        if(!intersection)
            return nullptr;
        
        while(head != intersection)
        {
            head = head->next;
            intersection = intersection->next;
        }
            
        return intersection;
    }
    
    ListNode *getIntersection(ListNode *head)
    {
        ListNode *slow{head}, *fast{head};
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                return slow;
        }
        
        return nullptr;
    }
};