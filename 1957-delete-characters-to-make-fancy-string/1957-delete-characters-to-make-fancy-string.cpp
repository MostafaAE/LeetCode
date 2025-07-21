/*
 * Approach:
 * The goal is to remove consecutive characters if any character appears more than twice in a row.
 * 
 * - Use a **two-pointer technique**:
 *   - Pointer `i` scans the string from left to right starting from index 2.
 *   - Pointer `j` keeps track of the position to overwrite in the final string.
 * - For each character, we check the last two added characters:
 *   - If the current character is **not the same** as the last two, we keep it.
 *   - Otherwise, skip it.
 * 
 * Time Complexity  : O(n), where n is the length of the string. We scan the string once.
 * Space Complexity : O(1), in-place modification of the input string.
 */

class Solution {
public:
    string makeFancyString(string s) 
    {
        int n = s.size();

        if (n < 3)
            return s;

        int j = 2;

        for (int i = 2; i < n; ++i)
        {
            // Only write if current character is not equal to the previous two
            if (s[i] != s[j - 1] || s[i] != s[j - 2])
            {
                s[j++] = s[i];
            }
        }

        s.resize(j);
        return s;
    }
};