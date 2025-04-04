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
     * 1. We perform a **Breadth-First Search (BFS)** to traverse the tree level by level.
     * 2. During BFS, we store each node's parent in the `valToParent` map for easy reference.
     * 3. After finishing the BFS, we know the deepest level nodes because they were processed last.
     * 4. We then use the parent map to find the **Lowest Common Ancestor (LCA)** of the deepest nodes.
     * 5. If only one node exists at the deepest level, that node is the LCA.
     * 6. Otherwise, we trace the parent pointers of all deepest nodes until we find the common ancestor.
     * 
     * Time Complexity:
     * - **O(N)** where N is the number of nodes in the tree. We visit each node once in the BFS and perform additional operations proportional to the number of deepest nodes.
     * Space Complexity:
     * - **O(N)** due to the queue used for BFS and the map used for storing parent references.
     */
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        unordered_map<int, TreeNode*> valToParent; // Map to store parent of each node
        queue<TreeNode*> q; // Queue to perform BFS traversal
        q.push(root);
        valToParent[root->val] = nullptr; // The root has no parent

        vector<TreeNode*> currentLevel, prevLevel;
        
        // Perform BFS traversal to process each level of the tree
        while(!q.empty())
        {
            int sz = q.size();
            currentLevel.clear(); // Clear current level nodes

            while(sz--)
            {
                TreeNode* cur = q.front();
                q.pop();
                currentLevel.push_back(cur); // Add current node to the current level

                // Add children to the queue and store their parent references
                if(cur->left)
                {
                    q.push(cur->left);
                    valToParent[cur->left->val] = cur;
                }
                if(cur->right)
                {
                    q.push(cur->right);
                    valToParent[cur->right->val] = cur;
                }
            }

            // After processing a level, update the previous level
            prevLevel = currentLevel;
        }

        // If only one node exists at the deepest level, that node is the LCA
        if(prevLevel.size() == 1)
        {
            return prevLevel.back();
        }

        // Otherwise, find the LCA of the deepest leaves
        return LCA(prevLevel, valToParent);
    }

    /**
     * Helper function to find the Lowest Common Ancestor (LCA) of the deepest nodes.
     * This function traces up the parent pointers of all the nodes at the deepest level
     * until a common ancestor is found.
     */
    TreeNode* LCA(vector<TreeNode*>& lastLevelVals, unordered_map<int, TreeNode*>& valToParent)
    {
        unordered_set<TreeNode*> currentParents; // Set to store parent nodes

        // Collect the parents of each node in the deepest level
        for(TreeNode* node : lastLevelVals)
        {
            currentParents.insert(valToParent[node->val]);
        }

        // Traverse up the parent chain until we find a common ancestor
        while(currentParents.size() > 1)
        {
            unordered_set<TreeNode*> nextParents;
            for(auto* parent : currentParents)
            {
                nextParents.insert(valToParent[parent->val]);
            }
            currentParents = nextParents; // Move to the next level of ancestors
        }

        // Only one common ancestor remains
        return *currentParents.begin();
    }
};