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
    /**
     * Approach:
     * 1. Use a level-order traversal (BFS) to traverse the binary tree level by level.
     * 2. At each level:
     *    - Find the maximum value among the nodes.
     *    - Add the maximum value to the result vector.
     * 3. Return the result vector after processing all levels.
     * 
     * Complexity:
     * Time Complexity: O(n) - Each node in the tree is visited exactly once during the traversal.
     * Space Complexity: O(w) - The queue can hold at most `w` nodes, where `w` is the maximum width of the tree.
     */
    vector<int> largestValues(TreeNode* root) 
    {
        if(!root)
            return {};
        
        vector<int> result;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            int maxVal = INT_MIN;
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
                maxVal = max(maxVal, cur->val);
            }
            
            result.push_back(maxVal);
        }
        
        return result;
    }
};