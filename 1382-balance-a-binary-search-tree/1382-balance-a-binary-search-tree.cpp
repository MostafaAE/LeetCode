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
    * Convert the tree to a sorted array using an in-order traversal, then construct a new balanced tree from the sorted array recursively.
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> traversal;
        dfs(root, traversal);
        
        return build(traversal, 0, (int)traversal.size()-1);
    }
    
    // O(n)
    TreeNode* build(vector<int> &traversal, int start, int end)
    {
        if(start > end)
            return nullptr;
        
        int mid = start + (end - start) / 2;
        
        TreeNode* node = new TreeNode(traversal[mid]);
        
        node->left = build(traversal, start, mid - 1);
        node->right = build(traversal, mid + 1, end);
        
        return node;
    }
    
    // O(n)
    void dfs(TreeNode* node, vector<int> &traversal)
    {
        if(!node)
            return;
        
        dfs(node->left, traversal);
        
        traversal.push_back(node->val);
        
        dfs(node->right, traversal);
    }
};