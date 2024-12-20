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
private:
    int sum = 0;
public:
    int sumRootToLeaf(TreeNode* root) 
    {
        dfs(root);
        return sum;
    }
    
    void dfs(TreeNode* node, string path = "")
    {
        if(!node)
            return;
        
        // leaf node
        if(!node->left && !node->right)
        {
            sum += binToValue(path + to_string(node->val));
            return;
        }

        dfs(node->left, path + to_string(node->val));
        dfs(node->right, path + to_string(node->val));
    }
    
    int binToValue(string str)
    {
        int val{}, n = str.size(), power = 1;
        for(int i = n - 1 ; i >= 0 ; --i)
        {
            if(str[i] == '1')
                val += power;
            power *= 2;
        }
        
        return val;
    }
};