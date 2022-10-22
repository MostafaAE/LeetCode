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
    * traverse the tree in dfs while pathing the current path sum to the children nodes
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    bool hasPathSum(TreeNode* root, int targetSum, int pathSum = 0) 
    {
        if(!root)
            return false;
        
        if(!root->left && !root->right && targetSum == pathSum+root->val)
            return true;
        
        return hasPathSum(root->left, targetSum, pathSum+root->val) 
            || hasPathSum(root->right, targetSum, pathSum+root->val);
        
    }
};