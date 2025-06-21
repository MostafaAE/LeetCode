/*
 * Approach:
 * - Greedy + Frequency Counting
 * - First, count frequency of each character in the string.
 * - Try to normalize all character frequencies to be in the range [a, a + k] where 'a' is the target frequency.
 * - For each target frequency 'a', calculate how many deletions are needed:
 *    - If b < a → we delete all b occurrences.
 *    - If b > a + k → we delete b - (a + k) occurrences to reduce it into range.
 * - The minimum deletions among all possible target frequencies is our result.
 *
 * Time Complexity:
 * - O(n + m^2), where:
 *    - n = size of word.
 *    - m = number of unique characters (at most 26 lowercase English letters → constant).
 * - So, effectively O(n).
 *
 * Space Complexity:
 * - O(m), storing frequencies in a map → O(26) → O(1) constant space.
 */

class Solution {
public:
    int minimumDeletions(string word, int k) 
    {
        unordered_map<char, int> cnt;
        
        // Count frequencies
        for (char ch : word) 
            ++cnt[ch];
        
        int result = word.size();

        // Try making every frequency 'a' the target
        for (auto &[_, a] : cnt) 
        {
            int deleted = 0;

            for (auto &[_, b] : cnt) 
            {
                if (a > b) 
                {
                    deleted += b; // Delete all b chars (too small)
                } 
                else if (b > a + k) 
                {
                    deleted += b - (a + k); // Delete excess to bring b into [a, a + k]
                }
            }

            result = min(result, deleted);
        }

        return result;
    }
};