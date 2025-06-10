class Solution {
public:
    /*
     * Approach:
     * - Use the KMP (Knuth-Morris-Pratt) prefix table (LPS array) to find the longest prefix
     *   of the string that is also a suffix.
     * - The LPS value at the last index represents the length of the longest proper prefix
     *   which is also a suffix.
     *
     * Time Complexity : O(n)
     *   - Single pass to build the LPS array.
     *
     * Space Complexity: O(n)
     *   - To store the LPS array.
     */
    string longestPrefix(string s) 
    {
        int m = s.size();
        vector<int> lps(m, 0); // LPS array

        int length = 0; // length of the previous longest prefix suffix
        int i = 1;

        while (i < m)
        {
            if (s[i] == s[length])
            {
                // Found a matching prefix-suffix character
                ++length;
                lps[i] = length;
                ++i;
            }
            else if (length != 0)
            {
                // Fallback to previous prefix length
                length = lps[length - 1];
            }
            else
            {
                // No prefix match at all
                lps[i] = 0;
                ++i;
            }
        }

        // The longest prefix which is also a suffix is of length lps[m - 1]
        return s.substr(0, lps[m - 1]);
    }
};