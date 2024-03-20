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
    /* 
    * Approach:
    * Parenthesize each subtree, and utilize a hash map to find the duplicate subtrees.
    * 
    * Complexity:
    * Time Complexity : O(n^2) => we visit every node O(n) and we will hash its representation O(n)
    * Space Complexity : O(n^2)
    */
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode*> result;
        unordered_map<string, int> hashMap;
        
        parenthesize(root, hashMap, result);
        
        return result;
    }
    
    string parenthesize(TreeNode* node, unordered_map<string, int>& hashMap, vector<TreeNode*>& result)
    {
        if(!node)
            return "()";
        
        
        string left = parenthesize(node->left, hashMap, result);
        string right = parenthesize(node->right, hashMap, result);
        string repr = "(" + to_string(node->val) + left + right + ")";
        
        hashMap[repr]++;
        
        // duplicate subtree
        if(hashMap[repr] == 2)
            result.push_back(node);
        
        return repr;
    }
};