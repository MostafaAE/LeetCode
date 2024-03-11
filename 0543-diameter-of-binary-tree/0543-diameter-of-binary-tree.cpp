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
     * Traverse the tree in dfs computing the height of each left and right subtree and maintaining the maximum diameter value.
     *
     * Complexity:
     * Time Complexity : O(n) 
     * Space Complexity : O(h) => auxiliary space for stack
    *  h could be (n) or (logn) depending on the shape of the tree
     */
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter{};
        
        dfs(root, diameter);
            
        return diameter;
    }
    
    int dfs(TreeNode* node, int& diameter)
    {
        if(!node)
            return -1;
        
        int leftHeight = dfs(node->left, diameter);
        int rightHeight = dfs(node->right, diameter);
        
        diameter = max(diameter, 2 + leftHeight + rightHeight);
        
        return 1 + max(leftHeight, rightHeight);
    }
    
};