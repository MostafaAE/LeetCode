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
        bool status = mn < root->val && root->val < mx;
        
        if(!status)
            return false;
        
        bool validLeft{1}, validRight{1};
        
        if(root->left)
            validLeft = isValidBST(root->left, mn, root->val);
        
        if(root->right)
            validRight = isValidBST(root->right, root->val, mx);
        
        return validLeft && validRight;
    }
};