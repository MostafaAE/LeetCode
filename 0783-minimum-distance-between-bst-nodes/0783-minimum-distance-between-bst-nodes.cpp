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
private:
    int minDist = INT_MAX;
    int lastVal = -1;
public:
    /* 
    * Approach: 
    * traverse the tree in inorder traversal to get the values sorted in increasing order and minimize the difference between each two consecutive values
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    int minDiffInBST(TreeNode* root) 
    {
        inorderTraversal(root);
        return minDist;
    }
    
    void inorderTraversal(TreeNode* node)
    {
        if(!node)
            return;
        
        inorderTraversal(node->left);
        
        if(lastVal != -1)
        {
            minDist = min(minDist, node->val - lastVal);
            lastVal = node->val;
        }
        else
            lastVal = node->val;
        
        inorderTraversal(node->right);
        
    }
};