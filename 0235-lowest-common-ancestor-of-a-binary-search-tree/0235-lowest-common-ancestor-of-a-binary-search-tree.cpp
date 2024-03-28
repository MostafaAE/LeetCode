/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    /* 
    * Approach:
    * Depth-First search
    * 
    * Complexity:
    * Time Complexity : O(h) => h could be (n) or (logn) depending on the shape of the tree
    * Space Complexity : O(1)
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode * cur = root;
        while(cur)
        {
            if(p->val < cur->val && q->val < cur->val)
                cur = cur->left;
        
            else if(p->val > cur->val && q->val > cur->val)
                cur = cur->right;
            
            else
                return cur;
        }
        
        return cur; 
    }
};