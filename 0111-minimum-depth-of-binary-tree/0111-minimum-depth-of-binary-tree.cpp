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
    int minDepth(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int l_depth = 1 + minDepth(root->left);
        int r_depth = 1 + minDepth(root->right);
        
        if(l_depth == 1 || r_depth == 1)
            return max(l_depth , r_depth);
        else
            return min(l_depth , r_depth);
        
    }
};