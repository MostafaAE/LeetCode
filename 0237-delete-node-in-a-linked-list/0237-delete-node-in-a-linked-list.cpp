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
    * - Copy the value of the next node to the current node and then delete the next node.
    *
    * Complexity:
    * - Time Complexity: O(1)
    * - Space Complexity: O(1)
    */
    void deleteNode(ListNode* node) {
        
        // get the next node
        ListNode* temp = node->next;
        
        // swap current node value with the next node value
        node->val = temp->val;
        
        // connect current node with next next
        node->next = temp->next;
        
        delete temp;
    }
};