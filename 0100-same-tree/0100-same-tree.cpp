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
    * Apply depth first search, checking if every node in p equals to q.
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n) => auxiliary space for stack
    */
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        return sameTree(p, q);
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