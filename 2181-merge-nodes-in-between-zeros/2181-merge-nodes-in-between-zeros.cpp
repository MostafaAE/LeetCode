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
    /**
     * Approach:
     * - Traverse the linked list starting from the node after the dummy head.
     * - For each segment of nodes between two zeroes, sum their values.
     * - Update the value of the first node of the segment with the sum.
     * - Link this node to the next segment's starting node.
     *
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(1)
     */
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* modify = head->next; // Start from the first node after the dummy head
        ListNode* nextSum = modify;
        
        while(nextSum)
        {
            int sum = 0;
            
            // Sum values until the next zero node
            while(nextSum->val != 0)
            {
                sum += nextSum->val;
                nextSum = nextSum->next;
            }
            
            modify->val = sum;
            
            // Move to the next segment
            nextSum = nextSum->next;
            // Link the modified node to the next segment
            modify->next = nextSum;
            // Move to the next node to be modified
            modify = modify->next; 
        }
        
        return head->next;
    }
};
