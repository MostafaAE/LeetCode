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
    * - Recursively traverse the linked list from head to tail.
    * - While traversing back from tail to head, compare the current node's value with the value of the next node.
    * - If the current node's value is less than the next node's value, remove the current node.
    *
    * Complexity:
    * - Time Complexity: O(n), where n is the number of nodes in the linked list.
    * - Space Complexity: O(n), auxiliary space for the recursive function calls.
    */
    ListNode* removeNodes(ListNode* node) 
    {
        if(node && node->next)
        {
            auto next = removeNodes(node->next);
            if(node->val < next->val)
            {
                delete node;
                return next;
            }
            
            node->next = next;
        }
        return node;
    }
};