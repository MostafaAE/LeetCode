class Solution {
public:
    /**
     * Approach:
     * 1. Use a stack to maintain the sequence of numbers.
     * 2. Iterate through the pattern:
     *    - Push the next number onto the stack.
     *    - If 'I' (increasing) is encountered or at the end of the pattern:
     *      - Pop all elements from the stack and append them to the result.
     *      - This ensures numbers are added in decreasing order when 'D' is encountered.
     * 3. Return the constructed smallest number.
     *
     * Complexity:
     * - Time Complexity: O(n), where `n` is the length of the pattern.
     *   - Each number is pushed and popped from the stack exactly once.
     * - Space Complexity: O(n) for the stack and the result string.
     **/
    string smallestNumber(string pattern) 
    {
        string result;
        stack<int> numStack;

        // Iterate through the pattern
        for (int index = 0; index <= pattern.size(); index++) 
        {
            // Push the next number onto the stack
            numStack.push(index + 1);

            // If 'I' is encountered or we reach the end, pop all stack elements
            if (index == pattern.size() || pattern[index] == 'I')
            {
                while (!numStack.empty()) 
                {
                    result += to_string(numStack.top());
                    numStack.pop();
                }
            }
        }

        return result;
    }
};
