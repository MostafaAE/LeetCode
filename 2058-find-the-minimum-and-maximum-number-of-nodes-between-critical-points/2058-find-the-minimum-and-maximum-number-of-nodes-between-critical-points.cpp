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
     * - Traverse the linked list to identify critical points.
     * - A critical point is defined as a node where the value is either a local maximum or a local minimum.
     * - Track the indices of the first and previous critical points.
     * - Calculate the minimum and maximum distances between critical points.
     * - Return {-1, -1} if fewer than two critical points are found.
     *
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(1)
     */
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        int minDistance = INT_MAX, maxDistance = -1;
        int firstCriticalPoint = -1, prevCriticalPoint = -1, idx = 1;
        
        ListNode* prev = head;
        ListNode* cur = head->next;
        
        while(cur && cur->next)
        {
            // Check if the current node is a critical point
            if((cur->val > prev->val && cur->val > cur->next->val) || 
               (cur->val < prev->val && cur->val < cur->next->val))
            {
                if(firstCriticalPoint == -1)
                    firstCriticalPoint = idx; // Mark the first critical point
                
                if(prevCriticalPoint != -1)
                    minDistance = min(minDistance, idx - prevCriticalPoint); // Update min distance
                
                prevCriticalPoint = idx; // Update previous critical point
            }
            
            prev = cur;
            cur = cur->next;
            ++idx;
        }
        
        if(minDistance == INT_MAX)
            return {-1, -1}; // If fewer than two critical points are found
        
        maxDistance = prevCriticalPoint - firstCriticalPoint; // Calculate max distance
        
        return {minDistance, maxDistance};
    }
};
