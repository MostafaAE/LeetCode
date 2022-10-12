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
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int rootIdx = (int)postorder.size()-1;
        int n = rootIdx;
        return build(inorder, postorder, rootIdx, 0, n);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int &rootIdx, int left, int right) 
    {
        if(left > right)
            return nullptr;
        
        int split = left;
        while(postorder[rootIdx] != inorder[split])
            split++;
        
        TreeNode *node = new TreeNode(postorder[rootIdx--]);
        
        node->right = build(inorder, postorder, rootIdx, split+1, right);
        node->left = build(inorder, postorder, rootIdx, left, split-1);
        
        return node;
        
    }
};