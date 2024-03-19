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
    * Get the parenthesize canonical representation of the two trees and compare them.
    * 
    * Complexity:
    * Time Complexity : O(N1 + N2)
    * Space Complexity : O(N1 + N2)
    */
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        string repr1 = parenthesizeCanonical(root1);
        string repr2 = parenthesizeCanonical(root2);
        
        return repr1 == repr2; 
    }
    
    string parenthesizeCanonical(TreeNode* node)
    {
        if(!node)
            return "()";
                
        int left = node->left ? node->left->val : -1;
        int right = node->right ? node->right->val : -1;
        
        string leftRepr = parenthesizeCanonical(node->left);
        string rightRepr = parenthesizeCanonical(node->right);
        
        if(left > right)
            swap(leftRepr, rightRepr);
        
        return "(" + to_string(node->val) + leftRepr + rightRepr + ")";
    }
};