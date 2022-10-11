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
    
    pair<int, int> diameterAndHeight(TreeNode *root)
    {
        pair<int, int> curDiamHeight = make_pair(0,0);
        
        if(!root->left && !root->right)
            return curDiamHeight;
        
        pair<int, int> leftDiamHeight = make_pair(0,0);
        pair<int, int> rightDiamHeight = make_pair(0,0);
        
        if(root->left)
        {
            leftDiamHeight = diameterAndHeight(root->left);
            curDiamHeight.first += 1 + leftDiamHeight.second;
        }
        
        if(root->right)
        {
            rightDiamHeight = diameterAndHeight(root->right);
            curDiamHeight.first += 1 + rightDiamHeight.second;
        }
        
        curDiamHeight.first = max(curDiamHeight.first, max(leftDiamHeight.first, rightDiamHeight.first));
        curDiamHeight.second = 1 + max(leftDiamHeight.second, rightDiamHeight.second);
        return curDiamHeight;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        pair<int, int> diamHeight = diameterAndHeight(root);
        return diamHeight.first;
    }
};