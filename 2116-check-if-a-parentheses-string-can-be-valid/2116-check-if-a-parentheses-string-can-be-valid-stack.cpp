class Solution {
public:
    /**
     * Approach:
     * - Use two stacks: one to store the indices of open brackets (`openBrackets`) 
     *   and another to store the indices of unlocked positions (`unlocked`).
     * - Traverse the string:
     *   - Push indices to the respective stacks for unlocked positions or open brackets.
     *   - Match close brackets with either `openBrackets` or `unlocked` indices.
     * - After traversal, match remaining open brackets with unlocked indices.
     *
     * Complexity:
     * - Time: O(n), single traversal and stack operations.
     * - Space: O(n), for storing indices in stacks.
     */
    bool canBeValid(string s, string locked) 
    {
        int n = s.size();

        if (n&1) 
            return false;

        stack<int> openBrackets, unlocked;

        // Iterate through the string to handle '(' and ')'
        for (int i = 0; i < n; i++) 
        {
            if (locked[i] == '0') 
                unlocked.push(i);
            
            else if (s[i] == '(') 
                openBrackets.push(i);
            
            else if (s[i] == ')') 
            {
                if (!openBrackets.empty()) 
                    openBrackets.pop();
                
                else if (!unlocked.empty()) 
                    unlocked.pop();
                
                else 
                    return false;
            }
        }

        // Match remaining open brackets with unlocked characters
        while (!openBrackets.empty() && !unlocked.empty() &&
               openBrackets.top() < unlocked.top()) 
        {
            openBrackets.pop();
            unlocked.pop();
        }

        if (!openBrackets.empty()) 
            return false;

        return true;
    }
};