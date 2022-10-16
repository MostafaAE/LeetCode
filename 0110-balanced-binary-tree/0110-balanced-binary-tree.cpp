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
    * traverse the tree in postorder traversal making sure every subtree is height-balanced
    * by checking the height difference of the left and right children of each node
    * if the abs(left-right) <= 1, then this subtree is balanced
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(h) => auxiliary space for stack
    * h could be (n) or (logn) depending on the shape of the tree
    */
    
    int treeHeight(TreeNode *node, bool &balanced)
    {
        
        if(!node->left && !node->right)
            return 0;
        
        int leftHeight{-1}, rightHeight{-1};
            
        if(node->left)
            leftHeight = treeHeight(node->left, balanced);
        
        if(balanced && node->right)
            rightHeight = treeHeight(node->right, balanced);
        
        if(balanced && abs(leftHeight-rightHeight) > 1)
            balanced = false;
        
        return 1 + max(leftHeight, rightHeight);
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
            return true;
        
        bool balanced = true;
        treeHeight(root, balanced);
        return balanced;
    }
};