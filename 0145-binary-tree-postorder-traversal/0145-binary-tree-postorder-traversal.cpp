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
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    void postorderTraversal(TreeNode* node, vector<int> &postorder) 
    {
        if(!node)
            return;
        
        postorderTraversal(node->left, postorder);
        postorderTraversal(node->right, postorder);  
        postorder.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> result;
        postorderTraversal(root, result);
        return result;
    }
};