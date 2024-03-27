/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /* 
    * Approach:
    * Traverse the tree to get the ancestors of both p and q nodes,then find the lowest common ancestor.
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*> ancestorsP, ancestorsQ;
        
        getAncestors(root, p, ancestorsP);
        getAncestors(root, q, ancestorsQ);
        
        unordered_set<TreeNode*> hashSet(ancestorsP.begin(), ancestorsP.end());
        
        for(int i = (int)ancestorsQ.size()-1 ; i >= 0 ; i--)
            if(hashSet.count(ancestorsQ[i]))
                return ancestorsQ[i];
        
        return nullptr;
    }
    
    bool getAncestors(TreeNode* node, TreeNode* target, vector<TreeNode*>& ancestors)
    {
        if(!node)
            return false;
        
        ancestors.push_back(node);
        
        if(node == target)
            return true;
        
        if(getAncestors(node->left, target, ancestors) || getAncestors(node->right, target, ancestors))
            return true;;
        
        ancestors.pop_back();
        return false;
    }
};