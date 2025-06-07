using ll = long long;

class Solution {
private:
    const int BASE = 26;
    const ll MOD = 1e9 + 7;

    /*
     * Helper Function: hasDuplicateSubstring
     * - Uses Rabin-Karp rolling hash to detect if there's any duplicate substring of length `len`.
     * - Maintains a hash map of hashes and starting indices for collision checking.
     */
    bool hasDuplicateSubstring(string& s, int len, int& startIdx)
    {
        int n = s.size();
        ll highestPower = 1;
        ll windowHash = 0;

        // Initial hash and highest power of BASE^(len-1)
        for (int i = 0; i < len; ++i)
        {
            windowHash = (windowHash * BASE + s[i] - 'a') % MOD;
            if (i < len - 1)
                highestPower = (highestPower * BASE) % MOD;
        }

        unordered_map<ll, vector<int>> hashMap;
        hashMap[windowHash].push_back(0);

        for (int i = len; i < n; ++i)
        {
            int curStart = i - len + 1;

            // Remove leftmost char and add new one
            ll leftChar = ((s[i - len] - 'a') * highestPower) % MOD;
            windowHash = (windowHash - leftChar + MOD) % MOD;
            windowHash = (windowHash * BASE + s[i] - 'a') % MOD;

            // Collision check by comparing substrings
            if (hashMap.count(windowHash))
            {
                for (int idx : hashMap[windowHash])
                {
                    if (s.substr(curStart, len) == s.substr(idx, len))
                    {
                        startIdx = idx;
                        return true;
                    }
                }
            }
            hashMap[windowHash].push_back(curStart);
        }

        return false;
    }

public:
    /*
     * Approach:
     * Binary Search + Rabin-Karp Rolling Hash
     * - Use binary search on substring lengths to find the longest duplicate substring.
     * - For each candidate length, use rolling hash to detect duplicates in linear time.
     * - Collision is resolved by checking actual substrings when hashes match.
     *
     * Time Complexity : O(n * log n)
     *   - Binary search runs in O(log n)
     *   - Each hash check runs in O(n), with occasional string comparisons
     *
     * Space Complexity: O(n), for storing hashes in the map
     */
    string longestDupSubstring(string s) 
    {
        int n = s.size();
        int start = 1, end = n - 1;
        int maxLen = 0, startIdx = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            int curStart = -1;
            if (hasDuplicateSubstring(s, mid, curStart))
            {
                maxLen = mid;
                startIdx = curStart;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return startIdx != -1 ? s.substr(startIdx, maxLen) : "";
    }
};