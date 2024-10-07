class Solution {
public:
    /**
     * Approach:
     * - Use a stack to simulate the process of removing pairs of characters "AB" and "CD".
     * - Traverse through each character in the string `s`:
     *   - If the current character forms a pair with the top of the stack (either "AB" or "CD"), pop the stack.
     *   - Otherwise, push the current character onto the stack.
     * - After processing the entire string, the remaining length of the string (after removing valid pairs) is returned.
     * 
     * Complexity:
     * - Time Complexity: O(n), where `n` is the length of the string. We process each character once.
     * - Space Complexity: O(n), for the stack, in the worst case when no pairs are removed.
     */
    int minLength(string s) 
    {
        stack<char> st;
        
        for(char c : s)
        {
            // If a valid pair is found, pop the stack and reduce the length
            if(!st.empty() && 
               ((c == 'B' && st.top() == 'A') ||
               (c == 'D' && st.top() == 'C')))
            {
                st.pop();
            }
            else
                st.push(c);  // Otherwise, push the character onto the stack
        }
        
        return st.size();
    }
};
