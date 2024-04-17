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
    * Traverse the tree in dfs passing the path string from the root
    * to the next child till we reach a leaf node, then while going back we compare every path string.
    *
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(n^2)
    */
    string smallestFromLeaf(TreeNode* root, string path = "") 
    {
        path = char(root->val + 'a') + path;
        
        // leaf node
        if(!root->left && !root->right)
            return path;

        if(root->left && root->right)
            return min(smallestFromLeaf(root->left, path), smallestFromLeaf(root->right, path));
        else if(root->left)
            return smallestFromLeaf(root->left, path);
        else
            return smallestFromLeaf(root->right, path);
    }
};