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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        
        int level{};
        while(!q.empty())
        {
            int sz = q.size();
            vector<TreeNode*> levelNodes;
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                
                if(level&1)
                    levelNodes.push_back(cur);
            }
            
            if(level&1)
                reverseLevel(levelNodes);
            
            ++level;
        }
        
        return root;
    }
    
    void reverseLevel(vector<TreeNode*>& levelNodes)
    {
        int left{}, right = levelNodes.size()-1;
        
        while(left <= right)
            swap(levelNodes[left++]->val, levelNodes[right--]->val);
    }
};