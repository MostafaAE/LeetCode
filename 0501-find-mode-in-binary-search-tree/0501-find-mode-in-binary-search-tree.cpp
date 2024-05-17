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
    * - Use a depth-first search (DFS) to traverse the binary tree and count the frequency of each value using a hashmap.
    * - Find the maximum frequency from the map.
    * - Collect all values with the maximum frequency and return them as the result.
    *
    * Complexity:
    * - Time Complexity: O(n), where n is the number of nodes in the binary tree.
    * - Space Complexity: O(n), for storing the frequency of each value in the hashmap.
    */
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> result;
        unordered_map<int, int> valToFreq;
        
        dfs(root, valToFreq);
        
        int maxFreq = 0;
        for(auto[val, freq] : valToFreq)
            maxFreq = max(maxFreq, freq);
        
        for(auto [val, freq] : valToFreq)
            if(freq == maxFreq)
                result.push_back(val);
        
        return result;
    }
    
    void dfs(TreeNode* node, unordered_map<int, int>& valToFreq)
    {
        if(!node)
            return;
        
        valToFreq[node->val]++;
        dfs(node->left, valToFreq);
        dfs(node->right, valToFreq);
    }
};