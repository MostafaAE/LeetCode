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
private:
    int idx = 0;                    // Tracks current position in the traversal string
    int currentDashesCount = 0;     // Tracks the number of dashes at the current level

    /**
     * Counts the number of consecutive dashes starting from the current index.
     * Used to determine the depth of the next node.
     **/
    int countDashesStartingFromIndex(string& str) 
    {
        int count{};
        while (idx < str.size() && str[idx] == '-') 
        {
            ++count;
            ++idx;
        }
        return count;
    }

    // Parses the next numeric value starting from the current index.
    string parseValueStartingFromIndex(string& str) 
    {
        string num{};
        while (idx < str.size() && isdigit(str[idx])) 
        {
            num += str[idx];
            ++idx;
        }
        return num;
    }

public:
    /**
     * Approach:
     * - Uses recursion to reconstruct the tree from the preorder traversal string.
     * - Parses numbers and determines node depth based on dashes.
     * - Recursively constructs left and right subtrees at the correct depth.
     * 
     * Complexity:
     * - Time Complexity: O(N), where N is the length of the traversal string.
     * - Space Complexity: O(H), where H is the height of the tree (recursion depth).
     **/
    TreeNode* recoverFromPreorder(string traversal, int level = 0) 
    {
        TreeNode* node = nullptr;
        
        // If we are at the correct level, create a node
        if (level == currentDashesCount) 
        {
            string num = parseValueStartingFromIndex(traversal);
            node = new TreeNode(stoi(num));

            // Count dashes to determine the next level
            currentDashesCount = countDashesStartingFromIndex(traversal);
            
            // Recursively build left and right children
            node->left = recoverFromPreorder(traversal, level + 1);
            node->right = recoverFromPreorder(traversal, level + 1);
        }

        return node;
    }
};
