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
stack<pair<TreeNode*, bool>> traversal;
public:
    BSTIterator(TreeNode* root) 
    {
        if(root)
            traversal.push({root, false});
    }
    
    int next() 
    {
        while(traversal.top().second == false)
        {
            TreeNode* cur = traversal.top().first;
            traversal.pop();
            
            if(cur->right)
                traversal.push({cur->right, false});
            
            traversal.push({cur, true});
            
            if(cur->left)
                traversal.push({cur->left, false});
        }
        
        TreeNode* cur = traversal.top().first;
        traversal.pop();
        return cur->val;
        
    }
    
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