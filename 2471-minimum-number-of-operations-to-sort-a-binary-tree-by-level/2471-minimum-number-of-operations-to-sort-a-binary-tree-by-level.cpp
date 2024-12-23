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
    int minimumOperations(TreeNode* root) 
    {
        int totalSwaps{};
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size(), misplaced{};
            vector<int> levelVals;
            for(int i = 0 ; i < sz ; ++i)
            {
                auto cur = q.front();
                q.pop();
                
                levelVals.push_back(cur->val);
                
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            
            totalSwaps += getMinSwaps(levelVals);
        }
        
        return totalSwaps;
    }
    
    int getMinSwaps(vector<int>& original) 
    {
        int swaps = 0;
        vector<int> target = original;
        sort(target.begin(), target.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < original.size(); i++) 
            pos[original[i]] = i;
        

        // For each position, swap until correct value is placed
        for (int i = 0; i < original.size(); i++) {
            if (original[i] != target[i]) 
            {
                swaps++;

                // Update position of swapped values
                int curPos = pos[target[i]];
                pos[original[i]] = curPos;
                swap(original[curPos], original[i]);
            }
        }
        
        return swaps;
    }
};