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
    
    // return (diameter, height)
    pair<int, int> treeDiameter(TreeNode *root)
    {
        pair<int, int> res = make_pair(0,0);
        
        if(!root->left && !root->right)
            return res;
        pair<int, int> leftData = make_pair(0,0);
        pair<int, int> rightData = make_pair(0,0);
        
        if(root->left)
        {
            leftData = treeDiameter(root->left);
            res.first += 1 + leftData.second;
        }
        if(root->right)
        {
            rightData = treeDiameter(root->right);
            res.first += 1 + rightData.second;
        }
        res.first = max(res.first, max(leftData.first, rightData.first));
        res.second = 1 + max(leftData.second, rightData.second);
        
        return res;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        pair<int,int> res = treeDiameter(root);
        return res.first;
        
    }
};