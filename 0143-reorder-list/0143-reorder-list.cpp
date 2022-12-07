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
    * Get the middle of the linkedlist, then reverse the linkedlist from the middle 
    * to the end ,and finally reorder the nodes
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    void reorderList(ListNode* head) 
    {
        // get the middle of the linkedlist
        ListNode *slow = head, *fast = head;
        while(fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        
        // slow is the middle of the linked list
        // let's reverse from the middle to the end
        ListNode* right = reverse(slow);
        
        // reorder the nodes
        ListNode* left = head;
        while(right)
        {
            ListNode* leftNext = left->next;
            ListNode* rightNext = right->next;
            
            if(!rightNext)
                leftNext = nullptr;
            
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