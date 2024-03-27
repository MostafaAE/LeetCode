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

class Comp{
public:
    int operator()(ListNode* node1, ListNode* node2){
        return (node1->val > node2->val);
    }
};

class Solution {
public:
    /* 
    * Approach:
    * Utilize a min heap to merge k sorted linked lists efficiently. Maintain a min heap of size k, where each element represents the head of one of the lists. Continuously extract the smallest node from the heap, append it to the merged list, and push its next node back into the heap if it exists. Repeat until the heap is empty, resulting in a merged list in ascending order.
    *
    * Another approach is to use Divide and Conquer (merge sort).
    * 
    * Complexity:
    * Time Complexity : O(nlogk)
    * Space Complexity : O(k)
    */
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // min heap
        priority_queue<ListNode*, vector<ListNode*>, Comp> minHeap;
        
        for(ListNode* list : lists)
            if(list)
                minHeap.push(list);
        
        ListNode *mergedList = new ListNode(0), *tail{mergedList};
        while(!minHeap.empty())
        {
            ListNode* top = minHeap.top();
            minHeap.pop();
            
            if(top->next)
                minHeap.push(top->next);
            
            tail->next = top;
            tail = tail->next;
        }
        
        return mergedList->next;
    }
};