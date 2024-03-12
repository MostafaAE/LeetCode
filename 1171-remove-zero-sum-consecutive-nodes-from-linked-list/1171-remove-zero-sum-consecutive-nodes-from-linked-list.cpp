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
     * Prefix sum with hash map.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0, head), *cur = dummy;
        
        unordered_map<int, ListNode*> prefixSumToNode;
        int sum{};
        prefixSumToNode[0] = dummy;
        
        while(cur)
        {
            sum += cur->val;
            prefixSumToNode[sum] = cur;
            cur = cur->next;
        }
        
        cur = dummy;
        sum = 0;
        
        // Remove zero sum consecutive sequences 
        while(cur)
        {
            sum += cur->val;
            cur->next = prefixSumToNode[sum]->next;
            cur = cur->next;
        }
        
        return dummy->next;   
    }
};