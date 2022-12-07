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
    * Complexity:
    * Time Complexity : O(max(m, n))
    * Space Complexity : O(max(m, n)) where m and n represents the length of l1 and l2 respectively
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        int carry{};
        while(l1 || l2 || carry)
        {
            int sum = carry;
            if(l1)
                sum += l1->val, l1 = l1->next;
            if(l2)
                sum += l2->val, l2 = l2->next;
            
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum / 10;
        }
        
        return dummyHead->next;
    }
};