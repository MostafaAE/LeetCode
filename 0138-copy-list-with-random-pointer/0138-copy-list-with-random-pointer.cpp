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
    * Iterate over the linkedlist mapping each old node to the new copy node, then iterate again to copy the pointers
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> oldToCopy{{nullptr, nullptr}};
        
        // map each old node to the new copy node
        Node* cur = head;
        while(cur)
        {
            Node* copy = new Node(cur->val);
            oldToCopy.insert({cur, copy});
            cur = cur->next;
        }
        
        // deep copy the pointers
        cur = head;
        while(cur)
        {
            Node* copy = oldToCopy[cur];
            copy->next = oldToCopy[cur->next];
            copy->random = oldToCopy[cur->random];
            cur = cur->next;
        }
        
        return oldToCopy[head];
    }
};