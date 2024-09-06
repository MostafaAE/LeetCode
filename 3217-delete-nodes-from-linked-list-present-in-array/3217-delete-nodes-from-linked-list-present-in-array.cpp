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
    /**
     * Approach:
     * - Create an unordered set from the `nums` vector to allow O(1) look-up for the values to be removed.
     * - Traverse the linked list using two pointers: `cur` (current node) and `prev` (previous node).
     * - If the value of the current node exists in the set, adjust the pointers to skip the node and delete it.
     * - If the value does not exist in the set, move both pointers to the next node.
     * - Return the modified head of the list.
     * 
     * Complexity:
     * - Time Complexity: O(n + m), where `n` is the number of nodes in the linked list and `m` is the size of the `nums` vector.
     * - Space Complexity: O(m), for storing the values to be removed in the unordered set.
     */
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        
        ListNode *prev = nullptr, *cur = head, *newHead = head;
        
        while(cur)
        {
            if(hashSet.count(cur->val))
            {
                if(prev == nullptr)
                {
                    newHead = cur->next;
                    delete cur;
                    cur = newHead;
                }
                else
                {
                    prev->next = cur->next;
                    delete cur;
                    cur = prev->next;
                }
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return newHead;
    }
};