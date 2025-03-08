class Solution {
public:
    /**
     * Approach:
     * - We use a **Sliding Window** technique to find the minimum number of white ('W') blocks 
     *   that need to be recolored in any substring of length `k`.
     * - We maintain a window of size `k` and track the count of 'W' blocks within it.
     * - As we slide the window across the string:
     *   - Add the new block at the right end.
     *   - Remove the block that exits from the left.
     *   - Update the minimum number of white blocks found.
     * - The final answer is the minimum number of 'W' blocks in any valid window.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n), where `n` is the length of the string.
     * - **Space Complexity**: O(1), as only a few integer variables are used.
     */
    int minimumRecolors(string blocks, int k) 
    {
        int n = blocks.size();
        int minWhiteCount{INT_MAX}, currentWhiteCount{};

        // Sliding window technique
        for(int i = 0; i < n; ++i)
        {
            if(i < k)
            {
                // Initialize the first window
                currentWhiteCount += blocks[i] == 'W';
            }
            else
            {
                // Update minimum count before sliding the window
                minWhiteCount = min(minWhiteCount, currentWhiteCount);
                // Expand window by adding new element
                currentWhiteCount += blocks[i] == 'W';
                // Shrink window by removing the leftmost element
                currentWhiteCount -= blocks[i - k] == 'W';
            }
        }

        // Consider the last window
        minWhiteCount = min(minWhiteCount, currentWhiteCount);

        return minWhiteCount;
    }
};
