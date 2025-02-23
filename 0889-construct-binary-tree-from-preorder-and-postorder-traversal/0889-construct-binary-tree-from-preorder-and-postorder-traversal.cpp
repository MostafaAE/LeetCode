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
     * - Uses a stack to iteratively reconstruct the tree.
     * - Maps postorder values to indices for quick lookup.
     * - Iterates through preorder to construct the tree while ensuring the correct parent-child relationship.
     * - Uses postorder index mapping to determine when to pop from the stack.
     *
     * Complexity:
     * - Time Complexity: O(N), where N is the number of nodes in the tree.
     * - Space Complexity: O(N) due to the stack and hashmap.
     */
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) 
    {
        int n = preorder.size();
        
        // Mapping postorder values to their indices for quick lookup
        unordered_map<int, int> postToIdx;
        for (int idx = 0; idx < n; ++idx) 
        {
            postToIdx[postorder[idx]] = idx;
        }

        // Stack to track the tree construction process
        stack<TreeNode*> treeStack;
        treeStack.push(new TreeNode(preorder[0]));

        for (int idx = 1; idx < n; ++idx) 
        {
            int currentVal = preorder[idx];
            int childPostIdx = postToIdx[currentVal];

            // Ensure correct parent-child relationships by popping until we find the right parent
            while (!treeStack.empty() && childPostIdx > postToIdx[treeStack.top()->val]) 
            {
                treeStack.pop();
            }

            TreeNode* curNode = new TreeNode(currentVal);

            // Attach as left or right child
            if (!treeStack.top()->left) {
                treeStack.top()->left = curNode;
            } else {
                treeStack.top()->right = curNode;
            }

            treeStack.push(curNode);
        }

        while (treeStack.size() > 1) 
        {
            treeStack.pop();
        }

        return treeStack.top();
    }
};
