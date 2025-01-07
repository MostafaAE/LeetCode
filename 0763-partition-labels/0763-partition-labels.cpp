class Solution {
public:
    /**
     * Approach:
     * - Use a hashmap to store the last occurrence of each character in the string.
     * - Traverse the string while maintaining a range (`startIndex` to `lastIndex`) that represents the current partition.
     * - If the current index reaches the `lastIndex`, it marks the end of a partition.
     *     - Append the size of the partition to the result.
     *     - Update `startIndex` for the next partition.
     * 
     * Complexity:
     * Time Complexity: O(n)
     * - First pass to build the hashmap takes O(n), where `n` is the length of the string.
     * - Second pass to determine partitions also takes O(n).
     * Space Complexity: O(1) (constant space usage for the hashmap, limited to 26 characters in the alphabet).
     */
    vector<int> partitionLabels(string s) 
    {
        int n = s.size();
        unordered_map<char, int> charToLastIndex;

        // Store the last occurrence of each character
        for (int i = 0; i < n; ++i)
            charToLastIndex[s[i]] = i;

        vector<int> result;
        int startIndex = 0, lastIndex = 0;

        // Traverse the string to find partitions
        for (int curIndex = 0; curIndex < n; ++curIndex) 
        {
            // Update the last index for the current partition
            lastIndex = max(lastIndex, charToLastIndex[s[curIndex]]);

            // If the current index reaches the end of the partition
            if (curIndex == lastIndex) 
            {
                result.push_back(lastIndex - startIndex + 1);
                startIndex = curIndex + 1; // Start a new partition
            }
        }

        return result;
    }
};
