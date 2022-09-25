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
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int start = 0, int end = -10) {
        
        if(end == -10)
            end = nums.size()-1;
        
        if(start > end)
            return nullptr;
        
        int mid = (start + end)/2;
        
        TreeNode * root = new TreeNode(nums[mid]);
        
        root->left = sortedArrayToBST(nums, start, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, end);
        
        return root;
        
    }
};