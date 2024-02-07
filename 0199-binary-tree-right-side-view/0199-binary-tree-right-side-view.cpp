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
    * Depth-First search (pick the rightmost node at each level)
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n) 
    */
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        
        dfs(root, result, 0);
        
        return result;
    }
    
    void dfs(TreeNode* node, vector<int> &result, int level)
    {
        if(!node)
            return;
        
        if(result.size() <= level)
            result.push_back(node->val);
       
        if(node->right)
            dfs(node->right, result, level + 1);
        if(node->left)
            dfs(node->left, result, level + 1);
    }
};