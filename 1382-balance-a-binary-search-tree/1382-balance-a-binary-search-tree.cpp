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
 * 1. Traverse the unbalanced BST using in-order traversal to get a sorted array of values.
 * 2. Recursively build a balanced BST from the sorted array by choosing the middle element as root.
 *    This ensures that the depth of the left and right subtrees remains balanced.
 *
 * Time Complexity  : O(n), where n is the number of nodes in the tree (due to traversal and reconstruction).
 * Space Complexity : O(n), for storing the in-order traversal result and recursive call stack.
 */

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int> inorderTraversal;

        // Step 1: Get sorted elements
        inOrderDFS(root, inorderTraversal); 

        // Step 2: Rebuild
        return buildBalancedBST(inorderTraversal, 0, inorderTraversal.size() - 1);
    }

private:
    // Helper function to perform in-order traversal and collect node values
    void inOrderDFS(TreeNode* node, vector<int>& result)
    {
        if (!node)
            return;

        inOrderDFS(node->left, result);
        result.push_back(node->val);
        inOrderDFS(node->right, result);
    }

    // Recursively build balanced BST from sorted array
    TreeNode* buildBalancedBST(const vector<int>& nums, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildBalancedBST(nums, left, mid - 1);
        root->right = buildBalancedBST(nums, mid + 1, right);

        return root;
    }
};