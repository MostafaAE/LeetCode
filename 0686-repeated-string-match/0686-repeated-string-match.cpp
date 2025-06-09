class Solution {
public:
    /*
     * Approach:
     * - Use the KMP (Knuth-Morris-Pratt) algorithm to check if the `pattern` can be found
     *   within repeated concatenations of `text`.
     * - We simulate repeating `text` while searching for `pattern`.
     * - Build the LPS (Longest Prefix Suffix) array to handle partial matches efficiently.
     *
     * Time Complexity : O(n + m)
     *   - n = text length, m = pattern length
     *   - LPS computation: O(m)
     *   - Matching: O(n * repeats + m), where repeats <= m / n + 2 → effectively O(m)
     *
     * Space Complexity: O(m)
     *   - For LPS array
     */
    int repeatedStringMatch(string text, string pattern) 
    {
        int textLength = text.size();
        int patternLength = pattern.size();

        vector<int> lps = buildLongestPrefixSuffixArray(pattern);

        int repeatCount = 1;
        int textIndex = 0;    // index in text
        int patternIndex = 0; // index in pattern

        // Worst-case we need text repeated (m/n + 2) times to cover all matches
        int maxRepeatCount = patternLength / textLength + 2;

        while (repeatCount <= maxRepeatCount)
        {
            // Match current characters
            if (text[textIndex] == pattern[patternIndex])
            {
                ++textIndex;
                ++patternIndex;

                // Full match found
                if (patternIndex == patternLength)
                    return repeatCount;
            }
            else
            {
                // Backtrack in pattern if possible
                if (patternIndex != 0)
                {
                    patternIndex = lps[patternIndex - 1];
                }
                else
                {
                    ++textIndex;
                }
            }

            // If we've reached the end of one repetition of `text`
            if (textIndex == textLength)
            {
                textIndex = 0;
                ++repeatCount;
            }
        }

        return -1; // Not found after maximum reasonable repetitions
    }

private:
    /*
     * Builds the LPS (Longest Prefix Suffix) array for KMP.
     * For each position i in pattern, LPS[i] is the length of the longest proper prefix
     * which is also a suffix for pattern[0..i]
     */
    vector<int> buildLongestPrefixSuffixArray(const string& pattern)
    {
        int m = pattern.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m)
        {
            if (pattern[i] == pattern[len])
            {
                ++len;
                lps[i] = len;
                ++i;
            }
            else if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                ++i;
            }
        }

        return lps;
    }
};