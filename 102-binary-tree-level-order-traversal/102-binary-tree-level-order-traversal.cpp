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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        
        if(!root)
            return result;
        
        queue<TreeNode *> qu;
        qu.push(root);
        
        while(!qu.empty())
        {
            int sz = qu.size();
            vector<int> level;
            
            while(sz--)
            {
                TreeNode *node = qu.front();
                qu.pop();

                level.push_back(node->val);

                if(node->left)
                    qu.push(node->left);
                if(node->right)
                    qu.push(node->right);
                
            }
            result.push_back(level);
        }
        
        return result;
        
    }
};