class Solution {
public:
    /**
     * Approach:
     * - Use a stack to store indices of open parentheses.
     * - Iterate through the string:
     *   - If the current character is '(', push the current length of the result string onto the stack.
     *   - If the current character is ')', pop the top index from the stack and reverse the substring
     *     from this index to the current end of the result string.
     *   - If the current character is a regular character, append it to the result string.
     * - The final result string will have the correct order after processing all parentheses.
     *
     * Complexity:
     * - Time Complexity: O(n^2) in the worst case
     * - Each reversal operation can take O(n) time, and in the worst case, this can be repeated n times.
     *
     * - Space Complexity: O(n)
     * - The stack can store at most n/2 indices in the worst case (when every other character is a '('),
     *   and the result string can grow to be the same size as the input string.
     */
    string reverseParentheses(string s) 
    {
        stack<int> openParenthesesIndices;
        string result;
        
        for (char currentChar : s) 
        {
            if (currentChar == '(') 
            {
                // Store the current length as the start index for future
                openParenthesesIndices.push(result.length());
            } 
            else if (currentChar == ')') 
            {
                int start = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                
                // Reverse the substring between the matching parentheses
                reverse(result.begin() + start, result.end());
            } 
            else 
            {
                result += currentChar;
            }
        }
        
        return result;
    }
};