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
    ListNode* reverseList(ListNode* head, ListNode **dummy) {
        
        if(!head || !head->next)
        {
            *dummy = head;
            return head;
        }
        
        ListNode *rem = reverseList(head->next, dummy);
        rem->next = head;
        head->next = nullptr;
        
        return head;
        
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode *newHead;
        reverseList(head, &newHead);
        return newHead;
    }
};