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
    * Iterate over the linkedlist using "Hare-And-Tortoise" pointers till the fast one reach the end
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        
        return slow;
    }
};