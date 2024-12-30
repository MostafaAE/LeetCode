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
    int averageOfSubtree(TreeNode* root) 
    {
        int nodesCount{};
        countNodes(root, nodesCount);
        return nodesCount;
    }

    pair<int, int> countNodes(TreeNode* node, int& nodesCount)
    {
        if(!node)
            return {0, 0};
        
        auto [leftSum, leftCount] = countNodes(node->left, nodesCount);
        auto [rightSum, rightCount] = countNodes(node->right, nodesCount);

        int subTreeSum = leftSum + rightSum + node->val;
        int subTreeCount = leftCount + rightCount + 1;
        
        if((subTreeSum / subTreeCount) == node->val)
            ++nodesCount;

        return {subTreeSum, subTreeCount};
    }
};