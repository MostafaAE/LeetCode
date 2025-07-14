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

/*
 * Approach:
 * The linked list represents a binary number, with the most significant bit at the head.
 * To convert it to an integer:
 * - Start from the head and for each node:
 *     - Left-shift the current result by 1 bit.
 *     - OR it with the current node's value to include the current bit.
 *
 * Time Complexity  : O(n), where n is the number of nodes in the list.
 * Space Complexity : O(1), constant space used.
 */

class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        int result = 0;
        ListNode* cur = head;

        while (cur)
        {
            result <<= 1;         // Shift result left by 1 to make room for the new bit
            result |= cur->val;   // OR with the current node's bit
            cur = cur->next;
        }

        return result;
    }
};
