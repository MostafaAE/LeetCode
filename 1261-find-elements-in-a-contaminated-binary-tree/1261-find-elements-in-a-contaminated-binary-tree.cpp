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
class FindElements {
private:
    unordered_set<int> seen;

    void recoverTree(TreeNode* node, int val)
    {
        if(!node)
            return;
        
        seen.insert(val);

        recoverTree(node->left, 2 * val + 1);
        recoverTree(node->right, 2 * val + 2);
    }
public:
    FindElements(TreeNode* root) 
    {
        recoverTree(root, 0);
    }
    
    bool find(int target) 
    {
        return seen.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */