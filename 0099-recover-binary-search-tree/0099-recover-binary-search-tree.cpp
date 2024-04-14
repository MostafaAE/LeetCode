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
    * Get the inorder traversal of the BST (sorted), iterate over the inorder traversal and find the two swapped node and recover them.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    void recoverTree(TreeNode* root) 
    {
        vector<TreeNode*> inorder;
        inorderTraversal(root, inorder);

        TreeNode *mn{nullptr}, *mx{nullptr};

        for(int i = 1 ; i < (int)inorder.size() ; i++)
        {
            if(inorder[i]->val < inorder[i-1]->val)
            {
                if(!mn)
                    mn = inorder[i], mx = inorder[i-1];
                else
                {
                    mn = inorder[i];
                    break;
                }
            }
        }
        
        swap(mn->val, mx->val);
    }

    void inorderTraversal(TreeNode* node, vector<TreeNode*>& traversal)
    {
        if(!node)
            return;
        
        inorderTraversal(node->left, traversal);
        traversal.push_back(node);
        inorderTraversal(node->right, traversal);
    }
};