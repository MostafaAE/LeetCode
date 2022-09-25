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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode *elem = new TreeNode(val);
        if(!root)
            return elem;
        
        TreeNode *cur = root;

        while (true)
        {
            if (val < cur->val)
            {
                if (cur->left)
                    cur = cur->left;
                else
                {
                    cur->left = elem;
                    break;
                }
            }

            else if (val > cur->val)
            {
                if (cur->right)
                    cur = cur->right;
                else
                {
                     cur->right = elem;
                    break;
                }
            }
        }
        return root;
        
    }
};