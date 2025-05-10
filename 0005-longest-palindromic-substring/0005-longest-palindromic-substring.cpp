const int MAX = 1001;
int memory[MAX][MAX];
string str;

class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming (Top-down with Memoization)
     * - We use memoization to cache results for each substring range (start, end).
     * - For every possible substring (start to end), check if it's a palindrome using recursion.
     * - Track the longest such palindrome seen.
     *
     * Complexity:
     * Time Complexity: O(n^2), where n is the length of the string. 
     *   - O(n^2) substrings and each memoized recursive call is O(1).
     * Space Complexity: O(n^2) for the DP memo table.
     */

    string longestPalindrome(string s) 
    {
        str = s;
        memset(memory, -1, sizeof(memory));

        int longestStart = 0, longestLength = 0;

        for (int start = 0; start < (int)str.size(); ++start) 
        {
            for (int end = start; end < (int)str.size(); ++end) 
            {
                if (isPalindrome(start, end) && (end - start + 1 > longestLength)) 
                {
                    longestStart = start;
                    longestLength = end - start + 1;
                }
            }
        }

        return str.substr(longestStart, longestLength);        
    }

private:
    bool isPalindrome(int startIdx, int endIdx)
    {
        // Base case: single char or empty range is a palindrome
        if (startIdx >= endIdx)
            return true;

        // Return cached result
        int &ret = memory[startIdx][endIdx];
        if (ret != -1)
            return ret;

        // If chars mismatch, it's not a palindrome
        if (str[startIdx] != str[endIdx])
            return ret = false;

        // Recurse on the inner substring
        return ret = isPalindrome(startIdx + 1, endIdx - 1);
    }
};