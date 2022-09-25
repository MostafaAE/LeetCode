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
    
    void preorderTraversal(TreeNode *node, vector<int> &preorder)
    {
        if (!node)
            return;

        preorder.push_back(node->val);
        preorderTraversal(node->left, preorder);
        preorderTraversal(node->right, preorder);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;
        preorderTraversal(root, result);
        return result;
    }
};