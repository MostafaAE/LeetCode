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
    /**
     * Approach:
     * - Convert the `to_delete` list into an unordered_set for O(1) average-time complexity checks.
     * - Use a recursive function to traverse the tree and delete nodes as specified.
     * - Maintain an unordered_map to keep track of current roots of the remaining trees.
     * - If a node needs to be deleted:
     *   - Remove it from the map if it is a root.
     *   - Add its children to the map as new roots if they are not null.
     *   - Recursively delete the node's children.
     * - If a node does not need to be deleted:
     *   - Recursively process its left and right children.
     *
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(n)
     */
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        if (!root)
            return {};
        
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        unordered_map<int, TreeNode*> valToRoot;
        valToRoot[root->val] = root;
        
        del(root, toDelete, valToRoot);
        
        vector<TreeNode*> result;
        for (auto& [val, root] : valToRoot)
            result.push_back(root);
        
        return result;
    }
    
private:
    void del(TreeNode* node, unordered_set<int>& toDelete, unordered_map<int, TreeNode*>& valToRoot, TreeNode* parent = nullptr, char dir = ' ')
    {
        if (!node)
            return;
        
        if (toDelete.count(node->val))
        {
            // Remove node from valToRoot if it was a root
            if (valToRoot.count(node->val))
                valToRoot.erase(node->val);
            
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            
            // Add children to valToRoot as new roots if they exist
            if (left)
                valToRoot[left->val] = left;
            if (right)
                valToRoot[right->val] = right;
            
            deleteNode(node, parent, dir);
            
            del(left, toDelete, valToRoot);
            del(right, toDelete, valToRoot);  
        }
        else
        {
            del(node->left, toDelete, valToRoot, node, 'L');
            del(node->right, toDelete, valToRoot, node, 'R');
        }
    }
    
    void deleteNode(TreeNode* node, TreeNode* parent, char dir)
    {
        if (parent)
        {
            if (dir == 'L')
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        delete node;
    }
};
