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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        queue<TreeNode *> qu;
        
        if(!root)
            return result;
        
        qu.push(root);

        int level = 0;

        while (!qu.empty())
        {
            int sz = (int)qu.size();
            vector<int> levelNodes;
            stack<int> reversedNodes;

            while(sz--)
            {
                TreeNode *node = qu.front();
                qu.pop();
                
                if(level%2)
                    reversedNodes.push(node->val);
                else
                    levelNodes.push_back(node->val);

                if(node->left)
                    qu.push(node->left);
                    
                if(node->right)
                    qu.push(node->right);
            }
            
            while(!reversedNodes.empty())
                levelNodes.push_back(reversedNodes.top()), reversedNodes.pop();
            
            result.push_back(levelNodes);
            
            level++;
            
        }
        
        return result;
        
    }
};