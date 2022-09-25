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

    int tree_height(TreeNode *root)
    {
        int height_l{}, height_r{};

        if (root->left)
            height_l = 1 + tree_height(root->left);

        if (root->right)
            height_r = 1 + tree_height(root->right);

        return max(height_l, height_r);
    }
    
    
    bool isCompleteTree(TreeNode* root) {
        
        int height = tree_height(root);
        
        queue<TreeNode *> qu;
        qu.push(root);

        bool end = false;
        
        while (!qu.empty())
        {
            int sz = (int)qu.size();

            while (sz--)
            {
                TreeNode *cur = qu.front();
                qu.pop();

                if (cur->left)
                {
                    if(end)
                        return false;
                    qu.push(cur->left);
                }
                else
                    end = true;
                
                if (cur->right)
                {
                    if(end)
                        return false;
                    qu.push(cur->right);
                }
                else
                    end = true;
            }

        }
        return true;
        
    }
};