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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> result;
        stack<pair<TreeNode *, bool>> nodes;
        
        if(root)
            nodes.push(make_pair(root, false));

        while (!nodes.empty())
        {
            TreeNode *current = nodes.top().first;
            bool is_done = nodes.top().second;
            nodes.pop();

            if (is_done)
                result.push_back(current->val);
            
            else
            {
                if (current->right)
                    nodes.push(make_pair(current->right, false));

                nodes.push(make_pair(current, true));

                if (current->left)
                    nodes.push(make_pair(current->left, false));
            }
        }
        
        return result;
        
    }
};