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
    * 1. Find the middle: use the slow and fast pointer technique to find the middle of the linked list.
    * 2. Reverse the second half: once you find the middle, reverse the second half of the linked list. 
    * 3. Reorder the nodes: merge the first half of the list with the reversed second half by alternating their nodes.
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    void reorderList(ListNode* head) 
    {
        // get the middle of the linkedlist
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        
        // slow is the middle of the linked list
        // let's reverse from the middle to the end
        ListNode* right = reverse(slow->next);
        slow->next = nullptr;
        
        // reorder the nodes (merge the two lists)
        ListNode* left = head;
        while(right)
        {
            ListNode* leftNext = left->next;
            ListNode* rightNext = right->next;
            
            left->next = right;
            right->next = leftNext;
            
            left = leftNext;
            right = rightNext;
        }
    }
    
    ListNode* reverse(ListNode* node)
    {
        ListNode* cur = node, *prev = nullptr;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};