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
    * Traverse the tree in level-order traversal (bfs) and keep the last node in each level
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        vector<int> result;
        q.push(root);
        
        while(!q.empty())
        {
            int sz = (int)q.size();
            
            while(sz--)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                // rightmost node in this level
                if(!sz)
                    result.push_back(cur->val);
                
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return result;
    }
};