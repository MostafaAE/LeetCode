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
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    int minDepth(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int l_depth = minDepth(root->left);
        int r_depth = minDepth(root->right);
        
        if(!l_depth || !r_depth)
            return 1 + max(l_depth , r_depth);
        else
            return 1 + min(l_depth , r_depth);
        
    }
};