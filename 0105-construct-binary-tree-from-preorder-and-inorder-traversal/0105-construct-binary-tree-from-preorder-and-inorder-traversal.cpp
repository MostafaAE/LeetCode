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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx{};
        int n = (int)preorder.size()-1;
        return build(preorder, inorder, rootIdx, 0, n);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int left, int right)
    {
        if(left > right)
            return nullptr;
        
       
        int split = left;
        while(preorder[rootIdx] != inorder[split])
            split++;
        
        TreeNode *node = new TreeNode(preorder[rootIdx++]);

        node->left = build(preorder, inorder, rootIdx, left, split-1);
        node->right = build(preorder, inorder, rootIdx, split+1, right);
        return node;
    }
};