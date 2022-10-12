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
    
    int maxDepth{-1};
    int leftmostVal{};
    void findBottomLeftValue(TreeNode* root, int depth) 
    {
        // leftmost
        if(!root->left && !root->right && depth > maxDepth)
        {
            leftmostVal = root->val;
            maxDepth = depth;
            return;
        }
        
        if(root->left)
            findBottomLeftValue(root->left, depth+1);
        
        if(root->right)
            findBottomLeftValue(root->right, depth+1);
        
    }
    int findBottomLeftValue(TreeNode* root) 
    {
        findBottomLeftValue(root, 0);
        return leftmostVal;
    }
};