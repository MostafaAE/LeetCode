/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * Approach:
 * The idea is to traverse both lists and switch heads when reaching the end.
 * - Pointer A starts at headA and pointer B starts at headB.
 * - When either reaches the end of its list, it jumps to the head of the other list.
 * - If the lists intersect, the pointers will meet at the intersection node after at most (m + n) steps.
 * - If not, both will end up being nullptr at the same time and the loop exits.
 *
 * Time Complexity  : O(m + n), where m and n are the lengths of the two lists.
 * Space Complexity : O(1), no extra space used.
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *curA = headA, *curB = headB;

        // Loop until the two pointers meet
        while (curA != curB)
        {
            // Move to next node or switch to the other list's head
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }

        return curA;
    }
};