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
    * Time Complexity : O(logn)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(!root)
            return nullptr;
        
        if(val == root->val)
            return root;
        
        else if (val < root->val)
            return searchBST(root->left, val);
        
        return searchBST(root->right, val);
    }
};