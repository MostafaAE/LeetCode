class Solution {
public:
    /**
     * Approach:
     * - Use a **Sliding Window with Bitwise Operations** to find the longest "nice" subarray.
     * - Maintain a **`usedBits`** variable to track the bitwise OR of all elements in the current window.
     * - If the new number (`nums[windowEnd]`) shares any bit with `usedBits`, **shrink** the window from the left 
     *   until there's no bit conflict.
     * - The key operation: `usedBits & nums[windowEnd] != 0` detects overlap in bits.
     * - Update the maximum length of the window during iteration.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n), where `n` is the number of elements in `nums`.
     * - **Space Complexity**: O(1)
     */
    int longestNiceSubarray(vector<int>& nums) 
    {
        int usedBits = 0;     // Tracks bits used in the current window
        int windowStart = 0;  // Start position of the current window
        int maxLength = 0;    // Length of the longest nice subarray found

        for (int windowEnd = 0; windowEnd < nums.size(); ++windowEnd) 
        {
            // If current number shares bits with `usedBits`, shrink the window from the left
            while ((usedBits & nums[windowEnd]) != 0) 
            {
                usedBits ^= nums[windowStart];  // Remove the leftmost element's bits
                ++windowStart;
            }

            // Add current number to the window
            usedBits |= nums[windowEnd];

            // Update max length if the current window is longer
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};
