/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode *> s;
        while(head && head->next)
        {
            if(!s.insert(head).second)
                return head;
            
            head = head->next;
        }
        
        return nullptr;
    }
};