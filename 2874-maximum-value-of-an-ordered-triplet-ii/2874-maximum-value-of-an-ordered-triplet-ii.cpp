class Solution {
public:
    /**
     * Approach:
     * 1. **Precompute Maximum Values**:
     *    - Use two arrays `leftMax` and `rightMax`:
     *      - `leftMax[i]`: Stores the maximum value from `nums[0]` to `nums[i]`.
     *      - `rightMax[i]`: Stores the maximum value from `nums[i]` to `nums[n-1]`.
     * 
     * 2. **Iterate Over Possible Middle Elements (`nums[i]`)**:
     *    - For each index `i` (1 ≤ i ≤ n-2), compute:
     *      (leftMax[i-1] - nums[i]) * rightMax[i+1]
     *    - Keep track of the maximum value found.
     *
     * Complexity Analysis:
     * - **Total Time Complexity**: **O(N)**.
     * - **Space Complexity**: **O(N)**
     */
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> leftMax(n, 0), rightMax(n, 0);

        // Step 1: Precompute leftMax and rightMax
        leftMax[0] = nums[0];
        rightMax[n - 1] = nums[n - 1];

        for (int i = 1; i < n; ++i) 
        {
            leftMax[i] = max(nums[i], leftMax[i - 1]);
            rightMax[n - i - 1] = max(nums[n - i - 1], rightMax[n - i]);
        }

        // Step 2: Compute the maximum triplet value
        long long result = 0;
        for (int i = 1; i < n - 1; ++i) 
        {
            long long curTripletVal = (long long)(leftMax[i - 1] - nums[i]) * rightMax[i + 1];
            result = max(result, curTripletVal);
        }

        return result;
    }
};
