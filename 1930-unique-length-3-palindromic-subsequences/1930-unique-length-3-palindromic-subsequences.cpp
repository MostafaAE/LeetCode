class Solution {
public:
    /**
     * Approach:
     * - Traverse the string `s` to find the first and last occurrence of each character.
     * - For each character with valid first and last indices:
     *     - Count the unique characters in the substring between the first and last indices.
     *     - Add the count to the result as these unique characters form palindromic subsequences.
     *
     * Complexity:
     * Time Complexity: O(26 * n) ≈ O(n)
     * - Finding the first and last occurrences of each character: O(n).
     * - Counting unique characters for at most 26 ranges: O(26 * n).
     * Space Complexity: O(26 + k) ≈ O(k)
     * - Space for storing first and last indices: O(26).
     * - Space for the set of unique characters: O(k), where `k` is the maximum substring length.
     */
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<pair<int, int>> charFirstAndLastIndices(26, {-1, -1});

        // Find first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            int charIdx = s[i] - 'a';
            if (charFirstAndLastIndices[charIdx].first == -1)
                charFirstAndLastIndices[charIdx].first = i;
            else
                charFirstAndLastIndices[charIdx].second = i;
        }

        int result = 0;
        // Count unique characters between first and last indices for each character
        for (auto& [firstIdx, lastIdx] : charFirstAndLastIndices) {
            if (firstIdx != -1 && lastIdx != -1)
                result += countUniqueCharsInRange(s, firstIdx, lastIdx);
        }

        return result;
    }

    /**
     * Helper function to count unique characters in a range.
     * - Traverse the substring and insert characters into a set.
     * - Return the size of the set.
     *
     * Complexity:
     * Time Complexity: O(end - start)
     * - Traversing the range between `start` and `end`.
     * Space Complexity: O(k), where `k` is the number of unique characters in the range.
     */
    int countUniqueCharsInRange(const string& s, int start, int end) {
        unordered_set<char> uniqueChars;
        for (int i = start + 1; i < end; ++i)
            uniqueChars.insert(s[i]);

        return uniqueChars.size();
    }
};
