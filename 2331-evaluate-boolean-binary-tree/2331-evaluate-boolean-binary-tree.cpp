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
    * - Recursively evaluate each node in the binary tree.
    * - If the node is a leaf node, return its value.
    * - If the node is an operator node (value is 2 or 3), recursively evaluate its left and right subtrees.
    * - Depending on the operator (OR or AND), return the result of the evaluation.
    *
    * Complexity:
    * - Time Complexity: O(n), where n is the number of nodes in the binary tree.
    * - Space Complexity: O(h), where h is the height of the binary tree (auxiliary space for stack `h` could be `(n)` or `(logn)` depending on the shape of the tree).
    */
    bool evaluateTree(TreeNode* root) 
    {
        // leaf node
        if(!root->left && !root->right)
            return root->val;
        
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        
        return root->val == 2 ? left | right : left & right;
    }
};