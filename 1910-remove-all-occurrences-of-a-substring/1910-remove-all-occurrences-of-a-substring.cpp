class Solution {
public:
    /**
     * Approach:
     * 1. Use a stack to store characters while iterating through the string.
     * 2. For each character in the input string:
     *    - Push it onto the stack.
     *    - If the stack's top matches the last `partLength` characters of `part`, remove them.
     * 3. After processing all characters, reconstruct the result string from the stack.
     * 4. Return the final string with all occurrences of `part` removed.
     *
     * Complexity:
     * - Time Complexity: O(n * m), where `n` is the length of `s` and `m` is the length of `part`. 
     *   - Each character is pushed onto the stack once.
     *   - In the worst case, checking for a match takes O(m) time.
     * - Space Complexity: O(n + m)
     **/
    string removeOccurrences(string s, string part) 
    {
        stack<char> stk;
        int strLength = s.length();
        int partLength = part.length();

        for (int index = 0; index < strLength; index++) 
        {
            stk.push(s[index]);

            // If stack size is greater than or equal to the part length, check for match
            if (stk.size() >= partLength && checkMatch(stk, part, partLength)) 
            {
                // Pop the characters matching 'part' from the stack
                for (int j = 0; j < partLength; j++) 
                    stk.pop();
            }
        }

        string result{};
        while (!stk.empty()) 
        {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }

private:
    // Helper function to check if the top of the stack matches the 'part'
    bool checkMatch(stack<char>& stk, string& part, int partLength) 
    {
        stack<char> temp = stk;

        for (int partIndex = partLength - 1; partIndex >= 0; partIndex--) 
        {
            // If current stack top doesn't match expected character
            if (temp.top() != part[partIndex]) 
                return false;
    
            temp.pop();
        }
        return true;
    }
};
