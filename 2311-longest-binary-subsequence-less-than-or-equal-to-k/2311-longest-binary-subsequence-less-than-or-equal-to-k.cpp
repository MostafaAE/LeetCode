/*
 * Approach:
 * We aim to find the longest subsequence (not necessarily contiguous) of binary digits from string `s`
 * such that its decimal value is less than or equal to `k`.
 * 
 * The optimal way is to:
 * 1. Always include all '0' characters, since they don't increase the decimal value.
 * 2. Try to include '1's starting from the least significant bit (i.e., from right to left).
 *    We maintain a running value and only include a '1' if adding it won't make the total exceed `k`.
 * 
 * Note: To prevent integer overflow (especially when `i >= 31`), we limit bits considered to `MAX_BITS = 31`.

 * Time Complexity  : O(n), where n = length of `s`.
 * Space Complexity : O(1), since only a few integer variables are used.
 */

class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int n = (int)s.size(), val = 0, count = 0;
        const int MAX_BITS = 31;

        for(int i = 0 ; i < n ; ++i)
        {
            // Traverse from least significant to most significant bit
            if(s[n - 1 - i] == '1')
            {
                // Only include if within safe bit range and value stays within `k`
                if(i < MAX_BITS && val + (1 << i) <= k)
                {
                    val += 1 << i;
                    ++count;
                }
            }
            else
            {
                // Always include '0'
                ++count;
            }
        }

        return count;
    }
};
