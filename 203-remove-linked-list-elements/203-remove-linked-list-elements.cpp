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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *cur = head, *prev = nullptr;
        
        while(cur)
        {
            if(cur->val == val)
            {
                 ListNode *temp = cur;
                // if node is first node
                if(cur == head)
                {
                    head = head->next;
                    cur = head;
                }
                else
                {
                    prev->next = cur->next;
                    cur = cur->next;
                }
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