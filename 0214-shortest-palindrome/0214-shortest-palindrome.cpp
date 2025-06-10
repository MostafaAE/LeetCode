class Solution {
public:
    /*
     * Approach:
     * - Use KMP (Knuth-Morris-Pratt) to find the longest prefix of the string that is also a suffix of its reversed form.
     * - To achieve this, we concatenate the original string `s`, a separator `#`, and the reversed string `rev(s)`.
     * - Build the LPS (longest prefix suffix) array for the combined string.
     * - The value at the last index of the LPS array gives the longest palindromic prefix.
     * - The remaining suffix (after the palindrome) needs to be added in reverse at the beginning to make the full string a palindrome.
     *
     * Time Complexity : O(n)
     *   - One pass to reverse the string, one pass to build the combined string,
     *     and one pass to compute the LPS array.
     *
     * Space Complexity: O(n)
     *   - For the reversed string, combined string, and LPS array.
     */
    string shortestPalindrome(string s) 
    {
        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        // Combine original + '#' + reversed to compute LPS
        string combined = s + "#" + reversed;

        // Compute LPS array for the combined string
        vector<int> lps = buildLongestPrefixSuffixArray(combined);

        // Length of longest palindromic prefix
        int lengthLongestPrefixSuffix = lps.back();

        // Characters after the palindrome prefix that need to be added in front
        int remainingSuffixLength = s.size() - lengthLongestPrefixSuffix;
        string missingCharacters = reversed.substr(0, remainingSuffixLength);

        return missingCharacters + s;
    }

private:
    // Build KMP LPS array for a given pattern
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
                lps[i++] = 0;
            }
        }

        return lps;
    }
};