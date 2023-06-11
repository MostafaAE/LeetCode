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
    * check each node's value if it can be a valid value or not
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    bool isValidBST(TreeNode* root, long long mn = LONG_LONG_MIN , long long mx = LONG_LONG_MAX) 
    {
        if(!root)
            return true;

        if(mn >= root->val || root->val >= mx)
            return false;

        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
    }
};