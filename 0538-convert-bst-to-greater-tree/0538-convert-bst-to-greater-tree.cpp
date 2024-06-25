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
     * - Perform a reverse in-order traversal (right, root, left) of the tree.
     * - Maintain a running sum of the nodes visited so far, and update each node's value to this running sum.
     * - The reverse in-order traversal ensures that we visit nodes in descending order.
     *
     * Complexity:
     * - Time Complexity: O(n), where n is the number of nodes in the tree.
     * - Space Complexity: O(h), where h is the height of the tree. Auxiliary space for stack `h` could be `(n)` or `(logn)` depending on the shape of the tree
     */
    TreeNode* convertBST(TreeNode* root) 
    {
        // Transform the tree
        greaterTree(root);  
        return root;
    }
    
    int greaterTree(TreeNode* root, int parentSum = 0)
    {
        // Base case: if the node is null, return the parent sum
        if (!root)  
            return parentSum;
        
        // Recursively transform the right subtree and get the sum of nodes visited so far
        int rightSum = greaterTree(root->right, parentSum);
        
        // Update the current node's value with the sum from the right subtree
        root->val += rightSum;
        
        // Recursively transform the left subtree, passing the updated value of the current node
        int leftSum = greaterTree(root->left, root->val);
        
        return leftSum;
    }
};