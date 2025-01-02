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
    int sumEvenGrandparent(TreeNode* root) 
    {
        int sum{};
        calculateSum(root, 1, 1, sum);
        return sum;
    }

    void calculateSum(TreeNode* node, int grandparent, int parent, int& sum)
    {
        if(!node)
            return;
        
        if(grandparent%2 == 0)
            sum += node->val;
        
        calculateSum(node->left, parent, node->val, sum);
        calculateSum(node->right, parent, node->val, sum);
    }
};