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
class BSTIterator {
private:
vector<int> inorder;
int itr{};
public:
    BSTIterator(TreeNode* root) 
    {
        inorderTraversal(root, inorder);
    }
    
    // O(1)
    int next() 
    {
        return inorder[itr++];
    }
    
    // O(1)
    bool hasNext() 
    {
        return itr < (int)inorder.size();
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& inorder)
    {
        if(!root)
            return;
        
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right, inorder);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */