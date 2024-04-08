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
stack<TreeNode*> traversal;
public:

    BSTIterator(TreeNode* root) 
    {
        addLeftMostChain(root);
    }
    
    void addLeftMostChain(TreeNode* node)
    {
        while(node)
        {
            traversal.push(node);
            node = node->left;
        }
    }
    
    // average O(1)
    int next() 
    {
        TreeNode* cur = traversal.top();
        traversal.pop();
        
        addLeftMostChain(cur->right);
        
        return cur->val;
    }
    
    // O(1)
    bool hasNext() 
    {
        return (int)traversal.size() != 0;
    }
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */