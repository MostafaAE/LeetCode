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
    * Iterate over the linkedlist and put all the nodes values in a stack, iterate again on the linked list
    * and compare each node's value with the top of the stack
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    bool isPalindrome(ListNode* head) 
    {
        stack<int> s;
        
        ListNode *cur = head;
        while(cur)
            s.push(cur->val), cur = cur->next;
        
        cur = head;
        while(!s.empty())
        {
            if(s.top() != cur->val)
                return false;
            
            s.pop();
            cur = cur->next;
        }
        
        return true;
    }
};