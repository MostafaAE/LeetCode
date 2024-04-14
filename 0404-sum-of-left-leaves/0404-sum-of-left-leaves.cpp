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
    * Depth-First search.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    int sumOfLeftLeaves(TreeNode* node, bool isLeft = 0) 
    {
        if(!node)
            return 0;
        
        // left leaf node
        if(!node->left && !node->right && isLeft)
            return node->val;

        return sumOfLeftLeaves(node->left, true) + sumOfLeftLeaves(node->right, false);
    }
};