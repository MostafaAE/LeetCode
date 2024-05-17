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
    * - Use a post-order traversal (left, right, root) to process leaf nodes first.
    * - Recursively remove leaf nodes with the target value from the left and right subtrees.
    * - If the current node becomes a leaf node and its value equals the target, return nullptr to remove it.
    * - Otherwise, return the current node.
    *
    * Complexity:
    * - Time Complexity: O(n), where n is the number of nodes in the binary tree.
    * - Space Complexity: O(h), where h is the height of the binary tree (auxiliary space for stack `h` could be `(n)` or `(logn)` depending on the shape of the tree).
    */
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        if(!root)
            return nullptr;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        
        if(root->val == target && !root->left && !root->right)
            return nullptr;
        
        return root;
    }
};