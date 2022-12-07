/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    /* 
    * Approach:
    * Iterate over the linkedlist while deep copying each node without the random pointer and mapping each old node
    * to the new copy, then iterate again to copy the random pointers using the hash map
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return nullptr;
        
        unordered_map<Node*, Node*> oldToNew;
        Node* newHead = new Node(head->val);
        Node* cpy = newHead;
        Node* cur = head->next;
        oldToNew.insert({head, newHead});
        
        // deep copy the nodes without the random pointers
        // and map each old node to the new node
        while(cur)
        {
            Node* node = new Node(cur->val);
            cpy->next = node;
            oldToNew.insert({cur, node});
            cur = cur->next;
            cpy = cpy->next;
        }
        
        // copy random pointers
        cur = head;
        cpy = newHead;
        while(cpy)
        {
            if(cur->random)
                cpy->random = oldToNew[cur->random];
            
            cur = cur->next;
            cpy = cpy->next;
        }
        
        return newHead;
    }
};