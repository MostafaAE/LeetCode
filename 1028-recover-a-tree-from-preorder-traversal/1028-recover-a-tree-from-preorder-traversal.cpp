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

class Solution 
{
private:
    /**
     * Counts the number of consecutive dashes in the traversal string.
     * This determines the depth of the next node.
     * 
     * Time Complexity: O(d), where d is the number of dashes.
     */
    int countDashesStartingFromIndex(string& str, int& idx)
    {
        int count = 0;
        while (idx < str.size() && str[idx] == '-')
        {
            ++count;
            ++idx;
        }
        return count;
    }

    /**
     * Parses an integer from the traversal string.
     * 
     * Time Complexity: O(log V), where V is the value of the parsed number.
     */
    int parseIntegerStartingFromIndex(string& str, int& idx)
    {
        int num = 0;
        while (idx < str.size() && isdigit(str[idx]))
        {
            num = num * 10 + (str[idx] - '0');
            ++idx;
        }
        return num;
    }

public:
    /**
     * Approach:
     * - Uses a stack to keep track of nodes at each depth.
     * - Iterates over the string, extracting values and depth levels.
     * - Uses the stack to correctly attach child nodes to their parents.
     * 
     * Complexity:
     * - Time Complexity: O(N), where N is the length of the traversal string.
     * - Space Complexity: O(H), where H is the height of the tree.
     */
    TreeNode* recoverFromPreorder(string traversal) 
    {
        stack<TreeNode*> stack;
        int index = 0;

        while (index < traversal.size()) 
        {
            // Count the number of dashes (depth of the current node)
            int depth = countDashesStartingFromIndex(traversal, index);

            // Extract the node value
            int value = parseIntegerStartingFromIndex(traversal, index);

            // Create the current node
            TreeNode* node = new TreeNode(value);

            // Adjust the stack to the correct depth
            while (stack.size() > depth) 
            {
                stack.pop();
            }

            // Attach the node to the parent
            if (!stack.empty()) 
            {
                if (stack.top()->left == nullptr) 
                {
                    stack.top()->left = node;
                } 
                else 
                {
                    stack.top()->right = node;
                }
            }

            // Push the current node onto the stack
            stack.push(node);
        }

        // The root is the first node in the stack
        while (stack.size() > 1) 
        {
            stack.pop();
        }

        return stack.top();
    }
};