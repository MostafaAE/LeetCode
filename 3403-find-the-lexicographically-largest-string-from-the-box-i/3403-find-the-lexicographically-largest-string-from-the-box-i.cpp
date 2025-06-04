class Solution 
{
public:
    /*
     * Approach:
     * Lexicographical Greedy Comparison
     * - We want the lexicographically largest substring of length (n - numFriends + 1).
     * - Iterate through the string and compare substrings starting at different positions.
     * - At each index, compare the substring of length maxLen starting from that index 
     *   with the current best using character-by-character comparison.
     * - Always keep the starting index of the best (largest) substring seen so far.
     * 
     * Time Complexity : O(n * k), where k = (n - numFriends + 1)
     * Space Complexity: O(1) extra space (ignoring output string)
     */
    string answerString(string word, int numFriends) 
    {
        if (numFriends == 1)
            return word;

        int n = (int)word.size(), maxLen = n - numFriends + 1, start = 0;

        for (int i = 1; i < n; ++i) 
        {
            start = findLexiLargestStart(word, i, start, maxLen);
        }

        return word.substr(start, maxLen);
    }

private:
    /*
     * Helper function to compare substrings of length `maxLen`
     * starting at `idx` and `previousStart`.
     * Returns the starting index of the lexicographically larger one.
     */
    int findLexiLargestStart(string& word, int idx, int previousStart, int maxLen) 
    {
        int n = (int)word.size(), cur = idx, prev = previousStart;

        for (int i = 0; i < maxLen && cur < n && prev < n; ++i, ++cur, ++prev) 
        {
            if (word[cur] > word[prev])
                return idx;
            else if (word[cur] < word[prev])
                return previousStart;
        }

        return previousStart;
    }
};