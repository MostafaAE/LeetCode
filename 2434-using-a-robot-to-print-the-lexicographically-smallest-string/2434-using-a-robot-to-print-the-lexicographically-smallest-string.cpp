class Solution 
{
public:
    /*
     * Approach:
     * Monotonic Stack + Greedy
     * - We simulate the robot operations by greedily choosing the smallest lexicographical character available
     *   that can be moved to the result string.
     * - Maintain the frequency of each character remaining in the input string.
     * - Use a stack to store characters we choose to delay.
     * - At each step, compare the current character with the smallest available in future (based on frequency).
     *   - If the stack top is <= the next smallest available character, pop from stack to result.
     *   - If the current character is the smallest remaining, add it to result directly.
     *   - Otherwise, push it to the stack to process later.
     * - Finally, empty the stack to the result string.
     *
     * Time Complexity : O(n)
     * Space Complexity: O(n)
     */
    string robotWithString(string s) 
    {
        vector<int> charFreq(26, 0);
        stack<char> st;

        // Count frequency of each character in the input
        for (char c : s)
            ++charFreq[c - 'a'];

        int nextSmallestCharIndex = 0;
        string result;

        for (char c : s)
        {
            // Update the smallest character still available in future
            nextSmallestCharIndex = getNextSmallestIndex(charFreq, nextSmallestCharIndex);
            char nextChar = nextSmallestCharIndex + 'a';

            // Pop all stack elements smaller or equal to the next smallest available char
            while (!st.empty() && st.top() <= nextChar)
            {
                result += st.top();
                st.pop();
            }

            if (c == nextChar)
            {
                result += c;
            }
            else
            {
                st.push(c);
            }

            --charFreq[c - 'a'];
        }

        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        return result;
    }

private:
    /*
     * Returns the index of the next smallest character (from `curIdx` onward)
     * that still exists in the remaining string.
     */
    int getNextSmallestIndex(vector<int>& charFreq, int curIdx)
    {
        for (int i = curIdx; i < (int)charFreq.size(); ++i)
        {
            if (charFreq[i])
                return i;
        }

        return (int)charFreq.size();
    }
};