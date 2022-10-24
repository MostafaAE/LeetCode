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
    * Time Complexity : O(n^2)
    * Space Complexity : O(n)
    */
    bool findTarget(TreeNode* root, int k, vector<int> &visited) 
    {
        if(!root)
            return false;
        
        for(int nodeVal : visited)
            if(nodeVal + root->val == k)
                return true;
        
        visited.push_back(root->val);
        
        bool foundLeft = findTarget(root->left, k, visited);

        bool foundRight = findTarget(root->right, k, visited);
        
        return foundLeft || foundRight;
    }
    bool findTarget(TreeNode* root, int k)
    {
        vector<int> visited;
        return findTarget(root, k , visited);
    }
};