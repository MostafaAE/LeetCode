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
    * traverse the tree in level-order traversal (bfs) 
    * and keep the last node in each level
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<TreeNode *> q;
        vector<int> result;
        
        if(root)
            q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                TreeNode *cur = q.front();
                q.pop();
                
                // rightmost node in this level
                if(sz == 0)
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