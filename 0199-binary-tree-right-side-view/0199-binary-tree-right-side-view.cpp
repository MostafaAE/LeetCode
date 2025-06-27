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
 
/*
 * Approach:
 * - Perform a depth-first search (DFS), prioritizing the right subtree first.
 * - For each level of the tree, we record the first node we visit (which will be the rightmost due to the right-first traversal).
 *
 * Time Complexity  : O(n), where n is the number of nodes in the tree.
 * Space Complexity : O(h), where h is the height of the tree (due to the recursion stack).
 *                    In the worst case (unbalanced tree), h = n. In the best case (balanced), h = log n.
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> result;

        // Start DFS traversal from root at level 0
        dfs(root, result, 0);

        return result;
    }

private:
    // Helper function for right-first DFS
    void dfs(TreeNode* node, vector<int>& result, int level)
    {
        if (!node)
            return;

        // If visiting this level for the first time, record the node's value
        if ((int)result.size() == level)
            result.push_back(node->val);

        // Visit right child first to prioritize rightmost nodes
        dfs(node->right, result, level + 1);

        // Then visit left child
        dfs(node->left, result, level + 1);
    }
};