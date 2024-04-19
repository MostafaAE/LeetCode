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
    * Traverse the tree in dfs calculating the maximum path passing through each node.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    int maxPathSum(TreeNode* root) 
    {
        int maxPath{INT_MIN};
        pathSum(root, maxPath);
        return maxPath;
    }
    
    int pathSum(TreeNode* node, int& maxPath)
    {
        if(!node)
            return 0;
        
        int left = pathSum(node->left, maxPath);
        int right = pathSum(node->right, maxPath);
        
        maxPath = max(maxPath, node->val + left + right);
        
        return max(0, max(left, right) + node->val) ;
    }
};