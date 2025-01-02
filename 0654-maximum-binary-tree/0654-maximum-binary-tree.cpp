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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return constructTree(nums, 0, nums.size()-1);
    }

    TreeNode* constructTree(vector<int>& nums, int left, int right)
    {
        if(left > right)
            return nullptr;

        int maxIndex = getMaxValueIndex(nums, left, right);

        TreeNode* node = new TreeNode(nums[maxIndex]);
        node->left = constructTree(nums, left, maxIndex - 1);
        node->right = constructTree(nums, maxIndex + 1, right);
        return node;
    }

    int getMaxValueIndex(vector<int>& nums, int left, int right)
    {
        int index{left};

        for(int i = left ; i <= right ; ++i)
            if(nums[i] > nums[index])
                index = i;

        return index;
    }
};