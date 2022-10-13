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
    
    /* Approach: 
     * traverse the tree in preorder traversal and set a threshold for the good nodes value
     * if the node value is greater than this threshold then it is a good node
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(h) => auxiliary space for stack
     * h could be (n) or (logn) depending on the shape of the tree
     */
    
    int goodNodes(TreeNode* node, int threshold = INT_MIN) 
    {
        int count{};
        if(node->val >= threshold)
            count++;
        
        if(node->left)
            count += goodNodes(node->left, max(threshold, node->val));
        
        if(node->right)
            count += goodNodes(node->right, max(threshold, node->val));
        
        return count;
        
    }
    
};