class Solution {
public:
    /**
     * Approach:
     * - Iterate through the array and flip every encountered `0` using a **greedy approach**.
     * - If `0` is found at index `i`, flip the next three elements (including `i` itself).
     * - If there are fewer than three elements remaining and a `0` is found, return `-1` since flipping is impossible.
     * - Count the number of flips performed.
     *
     * Complexity Analysis:
     * - **Time Complexity**: O(n), where `n` is the size of `nums`.
     * - **Space Complexity**: O(1)
     */
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size(), result = 0;

        for (int i = 0; i < n; ++i) 
        {
            if (!nums[i]) // If a zero is encountered
            {
                if (n - i < 3) // Not enough elements left to flip
                    return -1;

                ++result; // Count the operation

                // Flip the next three elements
                for (int j = i; j < n && j - i < 3; ++j)
                    nums[j] = !nums[j];
            }
        }

        return result;
    }
};
