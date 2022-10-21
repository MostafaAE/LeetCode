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
    * use queue to store each level's nodes then visit them in bfs
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;
        queue<TreeNode *> q;
        
        if(root)
            q.push(root);
    
        while(!q.empty())
        {
            int sz = q.size();
            vector<int> level;
            
            while(sz--)
            {
                TreeNode *cur = q.front();
                q.pop();
                level.push_back(cur->val);
                
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            result.push_back(level);
        }
        
        return result;
    }
};