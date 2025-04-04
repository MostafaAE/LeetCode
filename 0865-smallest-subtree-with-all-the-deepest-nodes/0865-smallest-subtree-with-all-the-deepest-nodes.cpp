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
    /**
     * Approach:
     * 1. We use a **Depth-First Search (DFS)** to traverse the tree.
     * 2. At each node, we compute the deepest level of the left and right subtrees.
     * 3. If the left subtree is deeper, the deepest node is in the left subtree.
     * 4. If the right subtree is deeper, the deepest node is in the right subtree.
     * 5. If both subtrees are of the same depth, the current node is the common ancestor of the deepest nodes.
     * 6. The function `dfs` returns both the node that is the root of the subtree containing all deepest nodes and the depth of that subtree.
     * 7. Finally, we return the root of the subtree that contains all the deepest nodes.
     * 
     * Time Complexity:
     * - **O(N)** where N is the number of nodes in the tree. We visit each node once to compute its depth and identify the deepest nodes.
     * Space Complexity:
     * - **O(H)** where H is the height of the tree due to the recursive call stack in DFS.
     */
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        return dfs(root).first; // Call DFS and return the root of the deepest subtree
    }

    /**
     * Helper function that performs DFS and returns the deepest subtree's root and its depth.
     * @param root The current node in the tree.
     * @return A pair where the first element is the node that is the root of the deepest subtree,
     *         and the second element is the depth of that subtree.
     */
    pair<TreeNode*, int> dfs(TreeNode* root) 
    {
        if (!root) 
            return {nullptr, 0}; // If the node is null, return null and depth 0

        // Perform DFS on the left and right children
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // If the left subtree is deeper, return the left subtree's result with an increased depth
        if (left.second > right.second) 
            return {left.first, left.second + 1};
        
        // If the right subtree is deeper, return the right subtree's result with an increased depth
        if (left.second < right.second) 
            return {right.first, right.second + 1};
        
        // If both subtrees are of the same depth, the current node is the LCA of all deepest nodes
        return {root, left.second + 1}; // Return the current node and the depth of its subtree
    }
};
