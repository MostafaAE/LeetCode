class Solution {
public:
    /**
     * Approach:
     * - The goal is to find indices of three non-overlapping subarrays of length `k` that have the maximum sum.
     * - Precompute the sum of all subarrays of length `k` starting from each index.
     * - Use dynamic programming to decide whether to include the current subarray or skip it, while tracking the maximum sum and indices.
     * - Reverse the result at the end since indices are pushed in reverse order during recursion.

     * Time Complexity: Overall: O(n)
     * - Precomputing subarray sums: O(n)
     * - Dynamic programming: O(n * 3) = O(n), where `n` is the size of the input array.
     *   - Each subproblem is solved at most once and has a constant factor of work per state.
     * 
     * Space Complexity: O(n * 3) for the DP table storing the maximum sums and their corresponding indices.
     */
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size(), sum{};
        vector<int> sumKStartingFromIdx(n, INT_MIN);

        // Precompute sum of all subarrays of length `k` starting from each index
        for (int i = n - 1; i >= 0; --i) 
        {
            sum += nums[i];
            if (n - i >= k) 
            {
                sumKStartingFromIdx[i] = sum;
                sum -= nums[i + k - 1];
            }
        }

        // DP table to store the maximum sum and indices for `remainingSubarrays`
        vector<vector<pair<int, vector<int>>>> maxSumToStartingIndecies(
            n, vector<pair<int, vector<int>>>(4, {INT_MIN, vector<int>()})
        );

        // Call the recursive DP function to solve the problem
        auto result = dp(0, 3, k, sumKStartingFromIdx, maxSumToStartingIndecies).second;
        
        // Reverse the result since indices are pushed in reverse order
        reverse(result.begin(), result.end());
        return result;
    }

    pair<int, vector<int>> dp(int idx, int remainingSubarrays, int k, 
                              vector<int>& sumKStartingFromIdx, 
                              vector<vector<pair<int, vector<int>>>>& maxSumToStartingIndecies) {
        // Base cases
        if (idx >= sumKStartingFromIdx.size() || remainingSubarrays == 0 || 
            (sumKStartingFromIdx[idx] == INT_MIN && remainingSubarrays > 0))
            return {0, vector<int>()};

        // Return cached result if already computed
        if (maxSumToStartingIndecies[idx][remainingSubarrays].first != INT_MIN)
            return maxSumToStartingIndecies[idx][remainingSubarrays];

        // Option 1: Pick the current subarray
        auto pick = dp(idx + k, remainingSubarrays - 1, k, sumKStartingFromIdx, maxSumToStartingIndecies);
        pick.first += sumKStartingFromIdx[idx];
        pick.second.push_back(idx);

        // Option 2: Skip the current subarray
        auto leave = dp(idx + 1, remainingSubarrays, k, sumKStartingFromIdx, maxSumToStartingIndecies);

        // Choose the better option
        if (pick.first >= leave.first)
            return maxSumToStartingIndecies[idx][remainingSubarrays] = pick;

        return maxSumToStartingIndecies[idx][remainingSubarrays] = leave;
    }
};
