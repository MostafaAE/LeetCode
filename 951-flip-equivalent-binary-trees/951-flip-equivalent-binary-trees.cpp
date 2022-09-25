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
    
    string parenthesize_canonical(TreeNode *node)
    {
        vector<string> v;
        
        if(!node)
            return "()";
        
        string repr = "(" + to_string(node->val);
        
        v.push_back(parenthesize_canonical(node->left));
        v.push_back(parenthesize_canonical(node->right));
        
        sort(v.begin(), v.end());
        
        for(string s : v)
            repr += s;
        
        repr+=")";
        
        return repr;
    }
    
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        string tree1 = parenthesize_canonical(root1);
        string tree2 = parenthesize_canonical(root2);
        
        return tree1 == tree2;
        
    }
};