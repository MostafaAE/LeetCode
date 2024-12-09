class Solution {
public:
    /**
     * Approach:
     * 1. Precompute a `prefix` array where:
     *    - `prefix[i]` stores the count of adjacent pairs of numbers with the same parity (even-even or odd-odd) up to index `i`.
     * 2. Traverse the input `nums` array:
     *    - If `nums[i]` and `nums[i-1]` have the same parity, increment `prefix[i]`.
     *    - Otherwise, copy the value from `prefix[i-1]`.
     * 3. For each query `[L, R]`:
     *    - Check if `prefix[L] == prefix[R]`. If true, all pairs in the range `[L, R]` have the same parity.
     * 4. Return a vector of booleans indicating the result for each query.
     * 
     * Complexity:
     * Time Complexity: O(n + q)
     * - O(n) to compute the `prefix` array.
     * - O(q) to process the queries.
     * Space Complexity: O(n)
     * - O(n) for the `prefix` array.
     */
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size(), q = queries.size();
        vector<int> prefix(n, 0);
        vector<bool> result(q);
        
        // Precompute prefix array
        for (int i = 1; i < n; ++i)
        {
            prefix[i] = prefix[i - 1];
            if ((nums[i] & 1) == (nums[i - 1] & 1)) // Same parity check
                ++prefix[i];
        }
        
        // Process each query
        for (int i = 0; i < q; ++i)
            result[i] = prefix[queries[i][1]] == prefix[queries[i][0]];
        
        return result;
    }
};
