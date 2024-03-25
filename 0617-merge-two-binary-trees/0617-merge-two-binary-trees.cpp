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
    * Traverse the two trees in dfs while merging each corresponding two nodes together.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(!root1)
            return root2;
        if(!root2)
            return root1;
        
        TreeNode* mergeNode = new TreeNode(root1->val + root2->val);
        
        mergeNode->left = mergeTrees(root1->left, root2->left);
        mergeNode->right = mergeTrees(root1->right, root2->right);
        
        return mergeNode;
    }
};