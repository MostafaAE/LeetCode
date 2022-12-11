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
        deque<TreeNode *> dq;
        
        if(!root)
            return result;
        
        dq.push_back(root);

        bool forwardLevel = true;

        while (!dq.empty())
        {
            int sz = (int)dq.size();
            vector<int> levelResult;
            
            while(sz--)
            {
                TreeNode *node;
                
                if(forwardLevel)
                {
                    node = dq.front();
                    dq.pop_front();

                    if(node->left)
                        dq.push_back(node->left);
                    if(node->right)
                        dq.push_back(node->right);
                }
                else
                {
                    node = dq.back();
                    dq.pop_back();

                    if(node->right)
                        dq.push_front(node->right);
                    if(node->left)
                        dq.push_front(node->left);
                }
                
                levelResult.push_back(node->val);
                
            }
            
            result.push_back(levelResult);
            forwardLevel = !forwardLevel;
            
        }
        
        return result;
        
    }
};