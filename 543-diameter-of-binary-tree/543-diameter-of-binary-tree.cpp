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
    
    int treeHeight(TreeNode* root)
    {
        int leftHeight{}, rightHeight{};
        
        if(root->left)
            leftHeight = 1 + treeHeight(root->left);
        if(root->right)
            rightHeight = 1 + treeHeight(root->right);
        
        return max(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int res {0}; 
        
        if(root->left)
            res += 1+ treeHeight(root->left);
        if(root->right)
            res += 1+ treeHeight(root->right);
        
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
        
    }
};