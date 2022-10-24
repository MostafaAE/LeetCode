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
    * Space Complexity : O(n)
    */
    bool findTarget(TreeNode* root, int k, unordered_set<int> &s) 
    {
        if(!root)
            return false;
        
        int diff = k - root->val;
        
        if(s.count(root->val))
            return true;
        
        s.insert(diff);
        
        return findTarget(root->left, k, s) || findTarget(root->right, k, s);
    }
    bool findTarget(TreeNode* root, int k)
    {
        unordered_set<int> s;
        return findTarget(root, k , s);
    }
};