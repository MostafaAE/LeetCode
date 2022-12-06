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
    * Store the reverse of the linked list in a stack then reorder the nodes
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    void reorderList(ListNode* head) 
    {
        stack<ListNode*> st;
        ListNode* cur = head;
        
        while(cur)
            st.push(cur), cur = cur->next;
        
        int n = (int)st.size()/2;
        cur = head;
        while(n--)
        {
            ListNode* next = cur->next;
            
            cur->next = st.top();
            st.pop();
            
            cur->next->next = next;
            cur = cur->next->next;
        }
        cur->next = nullptr;
    }
};