/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    */
    
    void preorder(Node* node, vector<int>& traversal) 
    {
        if(!node)
            return;
        
        traversal.push_back(node->val);
        for(Node* child : node->children)
            preorder(child, traversal);
            
    }
    vector<int> preorder(Node* root) 
    {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};