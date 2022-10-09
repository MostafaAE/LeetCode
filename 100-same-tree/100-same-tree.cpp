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
    
    string parenthesize(TreeNode *node)
    {
        if(!node)
            return "()";
        
        string repr = "(" + to_string(node->val);
        repr += parenthesize(node->left);
        repr += parenthesize(node->right);
        repr += ")";
        
        return repr;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        string pRepr = parenthesize(p);
        string qRepr = parenthesize(q);
        return (pRepr == qRepr);
    }
};