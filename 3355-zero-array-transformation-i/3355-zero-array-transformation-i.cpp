class Solution {
public:
    /*
     * Approach:
     * - Use a prefix sum difference array to efficiently apply multiple range updates.
     * - For each query [l, r], subtract 1 from nums[l..r] using the prefix trick:
     *     - prefix[l] -= 1
     *     - prefix[r+1] += 1
     * - Accumulate the prefix array to compute net effect at each index.
     * - Check if nums[i] + prefix[i] <= 0 for all i.
     * 
     * Time Complexity:
     * - O(Q) to process the queries
     * - O(N) to build the final prefix sum array
     * - O(N) to validate the array
     * => Total: O(N + Q)
     *
     * Space Complexity:
     * - O(N) for the prefix sum array
     */
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);

        // Apply each decrement operation using difference array technique
        for (auto& q : queries)
        {
            prefixSum[q[0]] -= 1;
            prefixSum[q[1] + 1] += 1;
        }

        // Build the prefix sum to reflect net changes at each index
        for (int i = 1; i < n; ++i)
        {
            prefixSum[i] += prefixSum[i - 1];
        }

        // Check if nums[i] + applied decrements <= 0 for all i
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] + prefixSum[i] > 0)
                return false;
        }

        return true;
    }
};