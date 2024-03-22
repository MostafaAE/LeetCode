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
    * 2. Reverse the second half: Once you find the middle, reverse the second half of the linked list. 
    * 3. Compare the halves: compare each element of the first half with its corresponding element in the reversed second half. If at any point we find a mismatch, the list is not a palindrome
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    bool isPalindrome(ListNode* head) 
    {
        ListNode *slow{head}, *fast{head->next};
        
        // find the middle of the linkedlist
        while(fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        
        // reverse the 2nd half of the linked list
        ListNode* head2 = reverse(slow->next);
        slow->next = nullptr;
        
        // compare the two halves
        while(head && head2)
        {
            if(head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev{nullptr};
        while(head)
        {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};