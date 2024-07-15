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
     * - Use an unordered_map to create and store TreeNode pointers for each unique value in descriptions.
     * - Use an unordered_set to keep track of all child nodes.
     * - Iterate through the descriptions:
     *   - If a node value does not exist in the map, create a new TreeNode and add it to the map.
     *   - Mark the child nodes in the unordered_set.
     *   - Link the parent node to the child node based on the relationship type (left or right).
     * - Find the root node by checking which node is not in the child set.
     *
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(n)
     */
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*> valToNode;
        unordered_set<int> childNodes;
        
        for(auto& v : descriptions)
        {
            childNodes.insert(v[1]);
            
            if(!valToNode.count(v[0]))
                valToNode[v[0]] = new TreeNode(v[0]);
            if(!valToNode.count(v[1]))
                valToNode[v[1]] = new TreeNode(v[1]);
            
            if(v[2] == 1)
                valToNode[v[0]]->left = valToNode[v[1]];
            else
                valToNode[v[0]]->right = valToNode[v[1]];
        }
        
        for(auto [val, node] : valToNode)
            if(!childNodes.count(val))
                return node;
        
        return nullptr;
    }
};