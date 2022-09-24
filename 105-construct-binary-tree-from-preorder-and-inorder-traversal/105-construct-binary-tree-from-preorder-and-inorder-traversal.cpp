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
        
        if(preorder.empty() || inorder.empty())
            return nullptr;
        
        TreeNode *node = new TreeNode(preorder.front());
        
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), preorder.front());
        
        preorder.erase(preorder.begin());
        vector<int> leftInorder(inorder.begin(), it);
        vector<int> rightInorder(it+1, inorder.end());
                                                  
        node->left = buildTree(preorder, leftInorder);
        node->right = buildTree(preorder, rightInorder);
        
        return node;
    }
};