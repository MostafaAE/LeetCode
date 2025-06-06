class Solution {
public:
    /*
     * Approach:
     * Monotonic Stack + Greedy Frequency Tracking
     * - Count frequency of all characters.
     * - Iterate over the input string, pushing each character to a stack.
     * - After each push, decrement the frequency and update the smallest remaining character.
     * - While the top of the stack is smaller than or equal to the smallest remaining character,
     *   pop it and add to the result (greedily place smallest available letters first).
     *
     * Time Complexity : O(n)
     * Space Complexity: O(n)
     */
    string robotWithString(string s) 
    {
        vector<int> charFreq(26, 0);
        
        // Count frequency of each character in the string
        for (char c : s)
            ++charFreq[c - 'a'];

        int nextSmallestCharIndex = 0;
        string result;
        stack<char> st;
        for (char c : s)
        {
            st.push(c);
            --charFreq[c - 'a'];

            // Update pointer to next smallest available character
            nextSmallestCharIndex = getNextSmallestIndex(charFreq, nextSmallestCharIndex);
            char nextChar = nextSmallestCharIndex + 'a';

            // Greedily pop from stack while top is <= next smallest character
            while (!st.empty() && st.top() <= nextChar)
            {
                result += st.top();
                st.pop();
            }
        }

        return result;
    }

private:
    // Helper to get index of next smallest available character
    int getNextSmallestIndex(vector<int>& charFreq, int curIdx)
    {
        while (curIdx < (int)charFreq.size() && charFreq[curIdx] == 0)
            ++curIdx;

        return curIdx;
    }
};