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
    int pairSum(ListNode* head) 
    {
        ListNode *middle = findMiddle(head);
        
        ListNode *end = reverse(middle);

        return getMaxPairSum(head, end);
    }

    int getMaxPairSum(ListNode* start, ListNode* end)
    {
        int result{};
        while(start && end)
        {
            result = max(result, start->val + end->val);
            start = start->next;
            end = end->next;
        }

        return result;
    }

    ListNode* findMiddle(ListNode* node)
    {
        ListNode *slow = node, *fast = node;
        while(fast)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* node)
    {
        ListNode *prev = nullptr, *cur = node;
        while(cur)
        {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }
};