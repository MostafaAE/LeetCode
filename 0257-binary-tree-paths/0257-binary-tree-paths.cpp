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
    void binaryTreePaths(TreeNode* root, vector<string> &paths, string path="")
    {   
        path += to_string(root->val);
        
        //leaf node
        if(!root->left && !root->right)
            return paths.push_back(path);
        
        if(root->left)
            binaryTreePaths(root->left, paths, path+"->");
            
        if(root->right)
            binaryTreePaths(root->right, paths, path+"->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> paths;
        binaryTreePaths(root, paths);
        return paths;
    }
};