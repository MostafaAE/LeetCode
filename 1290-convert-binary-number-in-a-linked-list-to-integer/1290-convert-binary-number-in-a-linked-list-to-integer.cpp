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
    * Iterate over the linkedlist, apply shift left and or operations to get the decimal value
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int getDecimalValue(ListNode* head) 
    {
        int val{};
        
        while(head)
        {
            val <<= 1;
            val |= head->val;
            head = head->next;
        }
        
        return val;
    }
};