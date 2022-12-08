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
private:
    stack<ListNode*> st;
public:
    /* 
    * Approach:
    * Store the linkedlist in a stack (reversed), calculate the rotation steps (k % size), and finally rotate the list
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(k == 0 || !head)
            return head;
        
        ListNode* cur = head;
        while(cur)
            st.push(cur), cur = cur->next;
        
        int steps = k % (int)st.size();
        
        while(steps--)
        {
            cur = st.top();
            st.pop();
            
            st.top()->next = nullptr;
            cur->next = head;
            head = cur;
        }
        
        return head;      
    }
};