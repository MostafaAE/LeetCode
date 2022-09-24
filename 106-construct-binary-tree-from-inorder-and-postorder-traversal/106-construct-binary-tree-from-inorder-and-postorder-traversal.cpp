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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(postorder.empty() || inorder.empty())
            return nullptr;
        
        TreeNode *node = new TreeNode(postorder.back());
        
        vector<int>::iterator it = find(inorder.begin(), inorder.end(), postorder.back());
        
        postorder.pop_back();
        vector<int> leftInorder(inorder.begin(), it);
        vector<int> rightInorder(it+1, inorder.end());
                                                  
        node->right = buildTree(rightInorder, postorder);
        node->left = buildTree(leftInorder, postorder);
        
        return node;
        
        
    }
};