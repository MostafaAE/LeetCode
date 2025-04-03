class Solution {
public:
    /**
     * Optimized O(N) approach using three tracking variables:
     * - leftMax: Keeps track of the maximum number encountered so far.
     * - diffMax: Tracks the maximum difference (leftMax - nums[i]) seen so far.
     * - result: Stores the maximum triplet value.
     *
     * Complexity:
     * - Time: O(N), since we iterate once through `nums`.
     * - Space: O(1), using only three variables.
     */
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();
        long long result = 0, leftMax = 0, diffMax = 0;

        for (int i = 0; i < n; ++i) 
        {
            // Compute the best triplet value so far
            result = max(result, diffMax * nums[i]);

            // Update the maximum (leftMax - nums[i]) found so far
            diffMax = max(diffMax, leftMax - nums[i]);

            // Update the leftMax for future calculations
            leftMax = max(leftMax, (long long)nums[i]);
        }

        return result;
    }
};
