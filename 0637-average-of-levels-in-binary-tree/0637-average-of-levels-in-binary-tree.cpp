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
     * Utilize level order traversal (BFS) to compute the average value of each level in the binary tree.
     * Use a queue to keep track of nodes at each level. At each level, compute the sum of node values
     * and count the number of nodes. Calculate the average and store it in the result vector.
     *
     * Complexity:
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            double levelSum{};
            int sz = q.size(), nodesCount=sz;
            while(sz--)
            {
                TreeNode* cur = q.front();
                q.pop();
                levelSum += cur->val;
                
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            result.push_back(levelSum/nodesCount);
        }
        
        return result;
    }
};