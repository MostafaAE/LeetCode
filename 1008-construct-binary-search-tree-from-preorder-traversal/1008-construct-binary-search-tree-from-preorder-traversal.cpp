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
     // O(n^2) solution
    TreeNode* bstFromPreorder(vector<int>& preorder, int start, int end) 
    {
        if(start > end)
            return nullptr;
        
        TreeNode *curRoot = new TreeNode(preorder[start]);
        
        int nextGreaterIdx = start+1;
        
        while(nextGreaterIdx <= end && preorder[nextGreaterIdx] < preorder[start])
            nextGreaterIdx++;
            
        curRoot->left = bstFromPreorder(preorder,start+1, nextGreaterIdx-1);
        curRoot->right = bstFromPreorder(preorder,nextGreaterIdx, end);
        
        return curRoot;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        return bstFromPreorder(preorder, 0, preorder.size()-1);
        
    }
};