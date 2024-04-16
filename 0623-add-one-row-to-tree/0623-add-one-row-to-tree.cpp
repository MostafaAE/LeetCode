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
    * Traverse the tree in dfs till we reach the desired depth and add the one row.
    *
    * Complexity:
    * Time Complexity : O(depth)
    * Space Complexity : O(depth) => auxiliary space for stack
    */
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth == 1)
        {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        addRow(root, val, depth, 1);
        return root;
    }
    
    void addRow(TreeNode* node, int val, int depth, int curDepth)
    {
        if(!node)
            return;
        
        if(curDepth == depth - 1)
        {
            TreeNode* leftNode = new TreeNode(val, node->left, nullptr);
            TreeNode* rightNode = new TreeNode(val, nullptr, node->right);
            node->left = leftNode;
            node->right = rightNode;
            return;
        }
        addRow(node->left, val, depth, curDepth + 1);
        addRow(node->right, val, depth, curDepth + 1);
    }
};