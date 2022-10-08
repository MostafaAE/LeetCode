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
    ListNode* deleteMiddle(ListNode* head) {
        
        // base cases
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
        {
            delete head;
            return nullptr;
        }
        
        // slow and fast pointers to reach the middle of the linked list
        ListNode *slow = head, *fast = head, *prev = nullptr;
        
        // tortoise and hare
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // slow is the middle node
        // delete it
        prev->next = slow->next;
        delete slow;
        return head;
        
    }
};