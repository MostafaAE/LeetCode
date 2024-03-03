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
    /*
     * Approach:
     * Use a hash table to check if a node is repeated.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode *> s;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            // Already exist (cycle)
            if(!s.insert(cur).second)
                return cur;
            
            cur = cur->next;
        }
        
        return nullptr;
    }
};