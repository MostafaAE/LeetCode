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
    * - Reverse the linked list.
    * - Traverse the reversed list while doubling each digit and handling carries.
    * - Reverse the list again.
    *
    * Complexity:
    * - Time Complexity: O(n), where n is the number of nodes in the linked list.
    * - Space Complexity: O(1).
    */
    ListNode* doubleIt(ListNode* head) 
    {
        head = reverse(head);
        ListNode* cur = head, *prev = nullptr;
        
        int carry{};
        while(cur)
        {
            cur->val *= 2;
            cur->val += carry;
            carry = cur->val / 10;
            cur->val %= 10;
            
            prev = cur;
            cur = cur->next;
        }
        
        if(carry)
            prev->next = new ListNode(carry);
    
        return reverse(head);
    }
    
    ListNode* reverse(ListNode* node)
    {
        ListNode* prev = nullptr, *cur = node;
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