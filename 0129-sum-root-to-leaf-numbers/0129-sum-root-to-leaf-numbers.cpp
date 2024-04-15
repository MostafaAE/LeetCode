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
    * Traverse the tree in preorder traversal (dfs) passing the path number from the root
    * to the next child till we reach a leaf node then sum the root-to-leaf numbers while going
    * back to the root again
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    int sumNumbers(TreeNode* root, int pathSum = 0) 
    {
        if(!root)
            return 0;
        
        pathSum = pathSum * 10 + root->val;
        
        // leaf node
        if(!root->left && !root->right)
            return pathSum;
        
        return sumNumbers(root->left, pathSum) + sumNumbers(root->right, pathSum);
    }
};