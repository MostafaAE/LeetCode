class Solution {
public:
    /**
     * Approach:
     * 1. Append a non-alphabetic character (e.g., `'.'`) to the string `s` as a sentinel.
     *    - This ensures the final sequence is processed without extra checks.
     * 2. For each character `'a'` to `'z'`:
     *    - Traverse the string and count the consecutive occurrences (`curLen`) of the current character.
     *    - When a different character is encountered, update a `lenToCount` map:
     *        - For each possible substring length `j` from `1` to `curLen`, increment the count of substrings of length `j`.
     *        - If the count of substrings of length `j` reaches or exceeds `3`, update the result with the maximum valid `j`.
     * 3. Reset `curLen` when the current character ends and repeat for the next character.
     * 4. Return the largest substring length that occurs at least three times.
     * 
     * Complexity:
     * Time Complexity: O(n)
     * - Outer loop runs 26 times (constant).
     * - The total work done by all inner loops combined is O(n).
     * Space Complexity: O(n)
     * - Space for the `lenToCount` map.
     */
    int maximumLength(string s) 
    {
        s += '.'; // Append a sentinel character
        
        int n = s.size(), result{-1};
        
        for (int c = 'a'; c <= 'z'; ++c)
        {
            int curLen = 0;
            unordered_map<int, int> lenToCount;
            
            for (int i = 0; i < n; ++i)
            {
                if (s[i] == c)
                    ++curLen;
                else
                {   
                    // Update lenToCount for the current sequence of character `c`
                    for (int j = 1; j <= curLen; ++j)
                    {
                        lenToCount[j] += curLen - j + 1;
                        if (lenToCount[j] >= 3 && j > result)
                            result = j; // Update the result with the maximum valid length
                    }
                    curLen = 0; // Reset current length
                }
            }
        }
        
        return result;
    }
};
