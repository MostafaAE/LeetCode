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
    * Use two pointers (left, right), where one of them ahead of the other by n nodes (right), then move both till the advancing pointer reaches the end (right), now we have the node preceding the node to be deleted (left).
    *
    * We can also solve it by getting the size on the linkedlist, then remove the nth node from the end.
    * We can also solve it in one pass by storing all the nodes in a vector then remove the target node but will be O(n) memory.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) 
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = new ListNode(0, head), *right{dummy}, *left{dummy};
        
        
        for(int i = 0 ; i < n ; i++)
            right = right->next;
        
        while(right && right->next)
            right = right->next, left = left->next;
        
        ListNode *temp = left->next;
        left->next = left->next->next;
        delete temp;
        
        head = dummy->next;
        delete dummy;
        
        return head;
    }
};