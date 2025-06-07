using ll = long long;

class Solution {
private:
    const int BASE = 26;
    const ll MOD = 1e9 + 7;

    // Helper to verify characters match to guard against hash collisions
    bool existFrom(int start, string& haystack, string& needle)
    {
        for (int i = 0; i < (int)needle.size(); ++i)
        {
            if (haystack[start + i] != needle[i])
                return false;
        }
        return true;
    }
public:
    /*
     * Approach:
     * Rabin-Karp (Rolling Hash) for Substring Search
     * - Compute the hash value of the needle and the first window of the haystack.
     * - Slide the window over the haystack, updating the rolling hash in O(1) per step.
     * - If a matching hash is found, confirm with a direct substring comparison to avoid false positives due to hash collisions.
     *
     * Time Complexity : O(n + m), where n = length of haystack, m = length of needle.
     * Space Complexity: O(1) extra space (excluding input storage).
     */
    int strStr(string haystack, string needle) 
    {
        if (needle.size() > haystack.size())
            return -1;

        int patternLength = needle.size();
        int textLength = haystack.size();

        ll highestPower = 1;
        for (int i = 0; i < patternLength - 1; ++i)
        {
            highestPower = (highestPower * BASE) % MOD;
        }

        ll patternHash = 0;
        ll windowHash = 0;
        for (int i = 0; i < patternLength; ++i)
        {
            patternHash = (patternHash * BASE + (needle[i] - 'a')) % MOD;
            windowHash = (windowHash * BASE + (haystack[i] - 'a')) % MOD;
        }

        for (int i = 0; i <= textLength - patternLength; ++i)
        {
            if (patternHash == windowHash && existFrom(i, haystack, needle))
            {
                return i;
            }

            // Remove the leftmost character and add the next character in the window
            if (i < textLength - patternLength)
            {
                ll leftChar = ((haystack[i] - 'a') * highestPower) % MOD;
                windowHash = (windowHash - leftChar + MOD) % MOD;
                windowHash = (windowHash * BASE + (haystack[i + patternLength] - 'a')) % MOD;
            }
        }

        return -1;
    }
};