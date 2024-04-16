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
    * - Tweak the original linked list. interweave the nodes of the old and copied list. 
    * For example: Old List: A --> B --> C --> D. InterWeaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'
    * Then connect the random pointers of the new list to the new nodes and finally split the two lists.
    *
    * - Another approach: Utilize a hashmap and iterate over the linkedlist mapping each old node to the new copy node, then iterate again to copy the pointers. O(n) space
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) => ignoring the new list space
    */
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return head;
        
        // tweak the original linked list.
        // interweave the nodes of the old and copied list.
        // For example: Old List: A --> B --> C --> D 
        // InterWeaved List: A --> A' --> B --> B' --> C --> C' --> D --> D'
        for(Node* cur = head ; cur ; cur = cur->next->next)
        {
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        
        // connect the random pointers to the new nodes
        for(Node* cur = head ; cur ; cur = cur->next->next)
            if(cur->random)
                cur->next->random = cur->random->next;
        
        // split the two linked lists
        Node* newHead = head->next;
        for(Node *cur = head ; cur ; cur = cur->next)
        {
            Node* copy = cur->next;
            cur->next = cur->next->next;
            if(copy->next)
                copy->next = copy->next->next;
        }
        
        return newHead;
    }
};