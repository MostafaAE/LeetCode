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
 * The problem requires us to partition a linked list into two parts:
 *  - One with nodes having values less than `x`
 *  - Another with nodes having values greater than or equal to `x`
 * 
 * We'll use two dummy nodes to build two separate lists and then merge them at the end.
 * 
 * Time Complexity  : O(n) where n is the number of nodes in the list (single pass).
 * Space Complexity : O(1) excluding the output (no extra data structures used, just pointers).
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        // Dummy nodes to anchor the two new lists
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterEqualHead = new ListNode(0);

        // Tail pointers for the two lists
        ListNode* lessTail = lessHead;
        ListNode* greaterEqualTail = greaterEqualHead;

        // Traverse the original list
        ListNode* current = head;
        while (current != nullptr)
        {
            if (current->val < x)
            {
                // Append to the 'less than x' list
                lessTail->next = current;
                lessTail = lessTail->next;
            }
            else
            {
                // Append to the 'greater or equal to x' list
                greaterEqualTail->next = current;
                greaterEqualTail = greaterEqualTail->next;
            }

            // Move to next node
            current = current->next;
        }

        // Terminate the greater list to avoid cycle
        greaterEqualTail->next = nullptr;

        // Link the end of the less list to the head of the greater list
        lessTail->next = greaterEqualHead->next;
        head = lessHead->next;

        // Free dummy nodes memory
        delete lessHead;
        delete greaterEqualHead;

        // Return the head of the combined list
        return head;
    }
};