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
    
    // get the node with minimum value O(h)
    TreeNode *minNode(TreeNode *root)
    {
        TreeNode *cur = root;
        while (cur && cur->left)
            cur = cur->left;

        return cur;
    }
    
    // delete the node with given key and return the updated tree
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (!root)
            return nullptr;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            // key == root->val
            // found the node: handle deletion

            TreeNode *temp = root;

            if (!root->left && !root->right) // case 1: leaf node
                root = nullptr;
            else if (!root->right) // case 2: 1 left child
                root = root->left;
            else if (!root->left) // case 2: 1 right child
                root = root->right;
            else // case 3: 2 children (left & right)
            {
                // find successor
                TreeNode *successor = minNode(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
                temp = nullptr;
            }

            if (temp)
                delete temp;
        }
        return root;
    }
    
};