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
     * Approach
     * Traverse the tree in postorder traversal but instead of recursing on left, and right children,
     * we have an array of children.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    vector<int> postorder(Node* root) 
    {
        vector<int> result;
        postorder(root, result);
        return result;
    }
    
    void postorder(Node* node, vector<int>& traversal)
    {
        if(node == nullptr)
            return;
        
        for(auto child : node->children)
            postorder(child, traversal);
        
        traversal.push_back(node->val);
    }
};