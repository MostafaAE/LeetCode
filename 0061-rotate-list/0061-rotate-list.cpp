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
    * Get the size of the linkedlist, calculate the rotation steps (k % size), and finally rotate the list at the pivot
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!k|| !head)
            return head;
        
        // get the size and tail of the linkedlist
        int size{1};
        ListNode* tail = head;
        while(tail->next)
            size++, tail = tail->next;
        
        // get the rotation steps
        k %= size;
        if(!k)
            return head;
        
        // get the pivot point
        ListNode* pivot = head;
        for(int i = 0 ; i < size - k - 1 ; i++)
            pivot = pivot->next;
        
        // reconnect the list
        ListNode* newHead = pivot->next;
        pivot->next = nullptr;
        tail->next = head;
        
        return newHead;      
    }
};