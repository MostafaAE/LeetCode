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
     * - Find the middle of the linked list using the slow and fast pointer technique.
     * - Reverse the second half of the linked list starting from the middle.
     * - Traverse the first half and reversed second half simultaneously to calculate the maximum twin sum.
     * 
     * Complexity:
     * Time Complexity: O(n)
     * - Finding the middle: O(n).
     * - Reversing the second half: O(n).
     * - Calculating the maximum twin sum: O(n).
     * Space Complexity: O(1)
     * - In-place operations are used for reversing the linked list.
     */
    int pairSum(ListNode* head) 
    {
        // Find the middle of the list
        ListNode* middle = findMiddle(head);

        // Reverse the second half of the list
        ListNode* end = reverse(middle);

        // Calculate the maximum twin sum
        return getMaxPairSum(head, end);
    }

private:
    // Helper function to find the middle of the linked list
    ListNode* findMiddle(ListNode* node) 
    {
        ListNode *slow = node, *fast = node;
        while (fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Helper function to reverse the linked list
    ListNode* reverse(ListNode* node) 
    {
        ListNode *prev = nullptr, *cur = node;
        while (cur) 
        {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }

    // Helper function to calculate the maximum twin sum
    int getMaxPairSum(ListNode* start, ListNode* end) 
    {
        int result = 0;
        while (end) // Iterate until the end of the reversed half
        {  
            result = max(result, start->val + end->val);
            start = start->next;
            end = end->next;
        }
        
        return result;
    }
};
