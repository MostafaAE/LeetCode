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
    * For each node in root, check if subRoot is the same tree (dfs)
    * 
    * Complexity:
    * Time Complexity : O(n * m) => where n is the size of tree and m is the size of sub tree
    * Space Complexity : O(m) => auxiliary space for stack
    */
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(sameTree(root, subRoot))
            return true;
        
        return (root->left && isSubtree(root->left, subRoot)) || (root->right && isSubtree(root->right, subRoot));
    }
    
    bool sameTree(TreeNode* t1, TreeNode* t2)
    {
        if(!t1 && !t2)
            return true;
                
        if(t1 && t2 && t1->val == t2->val)
            return sameTree(t1->left, t2->left) && sameTree(t1->right, t2->right);
        
        return false;    
    }
};