/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /* 
    * Approach:
    * Perform a depth-first search (DFS) traversal of the binary tree to find the parent and depth of the given nodes x and y.
    * While traversing, keep track of the parent and depth of each node.
    * Once both nodes are found, compare their parents and depths to determine if they are cousins.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    bool isCousins(TreeNode* root, int x, int y) 
    {
        // If one of the nodes is the root itself, they cannot be cousins.
        if(root->val == x || root->val == y)
            return false;
        
        // Vector to store the parent and depth of each node.
        vector<pair<int, int>> parentAndDepth;
        
        getParentAndDepth(root, x, y, parentAndDepth, 0);
        
        auto [parent1, depth1] = parentAndDepth[0];
        auto [parent2, depth2] = parentAndDepth[1];
        
        return parent1 != parent2 && depth1 == depth2;
    }
    
    void getParentAndDepth(TreeNode* node, int x, int y, vector<pair<int, int>>& parentAndDepth, int depth)
    {
        if(!node)
            return;
        
        if(node->left && (node->left->val == x || node->left->val == y))
            parentAndDepth.push_back({node->val, depth + 1});
        
        if(node->right && (node->right->val == x || node->right->val == y))
            parentAndDepth.push_back({node->val, depth + 1});
        
        if(parentAndDepth.size() == 2)
            return;
        
        getParentAndDepth(node->left, x, y, parentAndDepth, depth + 1);
        getParentAndDepth(node->right, x, y, parentAndDepth, depth + 1);
    }
};