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
    
    void inorderTraversal(TreeNode *node , vector<int> &inorder)
    {
        if (!node)
            return;

        inorderTraversal(node->left, inorder);
        inorder.push_back(node->val);
        inorderTraversal(node->right, inorder);
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> inorder = inorderTraversal(root);
        
        return inorder[k-1];
    }
};