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
    bool isValidBST(TreeNode* root, long long mn = LONG_LONG_MIN, long long mx = LONG_LONG_MAX) {
        
        bool status = mn < root->val && root->val < mx;
        
        if(!status)
            return false;
        
        bool left_bst = !root->left || isValidBST(root->left, mn, root->val);
        
        bool right_bst = !root->right || isValidBST(root->right, root->val , mx);

        
        return left_bst && right_bst;
        
    }
};