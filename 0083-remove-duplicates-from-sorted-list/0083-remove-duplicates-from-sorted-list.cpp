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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head)
            return head;
        
        ListNode *cur = head->next, *prev = head;
        
        while(cur)
        {
            if(prev->val == cur->val)
            {
                ListNode *temp = cur;
                cur = cur->next;
                prev->next = cur;
                delete temp;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return head;
    }
};