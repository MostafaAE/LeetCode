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
    
    string parenthesize(TreeNode *node, vector<pair<string,TreeNode *>> &allReps)
    {
        string repr;
        
        if (!node)
            return "()";
        
        repr += "(" + to_string(node->val);
        
        repr += parenthesize(node->right, allReps);
        repr += parenthesize(node->left, allReps);
        
        repr +=")";
        
        allReps.push_back(make_pair(repr, node));
        
        return repr;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode *> result;
        vector<pair<string, TreeNode *>> allReps;
        
        parenthesize(root, allReps);
        
        sort(allReps.begin(), allReps.end());

        for(int i = 0 ; i < (int)allReps.size();)
        {
            int j = i+1;
            
            while(j<(int)allReps.size() && allReps[i].first == allReps[j].first)
                j++;
            
            if(j > i+1)
                result.push_back(allReps[i].second);
            
            i=j;
        }
        
        return result;
        
    }
};