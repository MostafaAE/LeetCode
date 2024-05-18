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
    * - Use Postorder traversal (DFS) to traverse the tree.
    * - At each node, calculate the excess coins (positive value) or the lack of coins (negative value).
    * - Sum the absolute values of the excess or deficit of coins at each node to determine the total number of moves.
    * - The excess coins at a node are calculated as the sum of the excess coins from its left and right children, plus the coins at the current node, minus 1 (since each node should have exactly one coin).
    *
    * Complexity:
    * - Time Complexity: O(n), where n is the number of nodes in the tree.
    * - Space Complexity: O(h), where h is the height of the tree (auxiliary space for stack `h` could be `(n)` or `(logn)` depending on the shape of the tree)
    */
    int distributeCoins(TreeNode* root) 
    {
        int steps = 0;
        
        dfs(root, steps);
        
        return steps;
    }
    int dfs(TreeNode* node, int& steps)
    {
        if(!node)
            return 0;
        
        int left = dfs(node->left, steps);
        int right = dfs(node->right, steps);
        
        steps += abs(left) + abs(right);
        
        // Return the total excess coins at this node.
        return left + right + (node->val - 1);
    }
};