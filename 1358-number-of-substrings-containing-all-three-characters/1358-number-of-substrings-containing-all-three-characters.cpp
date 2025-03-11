class Solution 
{
public:
    /**
     * Approach:
     * - We use a **two-pointer sliding window** approach to count substrings containing at least one 'a', 'b', and 'c'.
     * - Expand the **right** pointer to include new characters in the window.
     * - When the window contains all three characters, count valid substrings and **shrink** the window from the left.
     * - The number of valid substrings is `(n - right)`, since any substring starting from `left` to `right` and extending to the end is valid.
     * - Move the **left** pointer until the window no longer contains all three characters.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n), since each character is processed at most twice (once when expanding, once when shrinking).
     * - **Space Complexity**: O(1), as we use a fixed hash map of size 3 for 'a', 'b', and 'c'.
     */
    int numberOfSubstrings(string s) 
    {
        unordered_map<char, int> charToCount;
        int n = s.size(), left{}, right{}, result{};

        while (right < n) 
        {
            // Expand window by including the character at 'right'
            ++charToCount[s[right]];

            // When all three characters are present, count valid substrings and shrink window
            while (charToCount['a'] && charToCount['b'] && charToCount['c']) 
            {
                result += n - right; // All substrings from 'left' to 'right' extending to 'n-1' are valid

                --charToCount[s[left]]; // Remove the leftmost character
                ++left; // Shrink window from the left
            }

            ++right;
        }

        return result;
    }
};