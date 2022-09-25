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

    //iterative approach
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode *> left;
        queue<TreeNode *> right;
        
        if(root->left)
            left.push(root->left);
        if(root->right)
            right.push(root->right);
        
        while(!left.empty() || !right.empty())
        {
            int leftSize = (int)left.size();
            int rightSize = (int)right.size();
            
            if(leftSize != rightSize)
                return false;
            
            while(leftSize--)
            {
                TreeNode *curLeft = left.front(); left.pop();
                
                TreeNode *curRight = right.front(); right.pop();
            

                if( (curLeft->val != curRight->val) || (curLeft->left && !curRight->right) 
                   || (!curLeft->left && curRight->right) || (curLeft->right && !curRight->left) 
                   || (!curLeft->right && curRight->left))
                    return false;
                
                if(curLeft->left && curRight->right)
                {
                    left.push(curLeft->left);
                    right.push(curRight->right);
                }
                    
                if(curLeft->right && curRight->left)
                {
                    left.push(curLeft->right);
                     right.push(curRight->left);
                    
                }
            }
        }
        return true;
        
    }
};