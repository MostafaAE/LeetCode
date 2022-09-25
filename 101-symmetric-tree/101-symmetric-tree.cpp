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
    
    string parenthesize(TreeNode *node, bool mirror)
    {
        string repr;
        
        if (!node)
            return "()";
        
        repr += "(" + to_string(node->val);
        
        if(mirror)
        {
            repr += parenthesize(node->right, mirror);
            repr += parenthesize(node->left, mirror);
        }
        else
        {
            repr += parenthesize(node->left, mirror);
            repr += parenthesize(node->right, mirror);
        }
        
        repr +=")";
        
        return repr;
    }
    
    
    bool isSymmetric(TreeNode* root) {
        
        string leftSubTree = parenthesize(root->left, false);
        string mirrorRightSubTree = parenthesize(root->right , true);
        return leftSubTree == mirrorRightSubTree;
        
    }
};