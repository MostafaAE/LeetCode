class Solution {
private:
    vector<int> nums;
    unordered_map<int, vector<int>> idxToResult;

public:
    /**
     * Approach:
     * 1. First, sort the input array in ascending order.
     * 2. For each index `i`, use DFS with memoization to find the longest divisible subset starting at that index.
     * 3. A number `nums[j]` can follow `nums[i]` in the subset only if `nums[j] % nums[i] == 0`.
     * 4. Cache results in `idxToResult` to avoid recomputation (top-down DP).
     * 5. Track the largest subset found across all indices.
     * 
     * Time Complexity: 
     * - O(N^2), where N is the size of `nums`. Each pair is checked at most once.
     * - Sorting takes O(N log N).
     * 
     * Space Complexity:
     * - O(N) for storing subsets in the memoization map, each subset will be at max of size 32.
     */
    vector<int> largestDivisibleSubset(vector<int>& _nums) 
    {
        nums = _nums;
        sort(nums.begin(), nums.end());  // Step 1: Sort the numbers to ensure divisibility checks are valid

        vector<int> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            vector<int> curResult = dfs(i);  // Step 2: Find largest subset starting from index i
            if (curResult.size() > result.size())
                result = curResult;  // Keep track of the longest subset
        }

        return result;
    }

    /**
     * Recursive function to compute the largest divisible subset starting at index `idx`.
     */
    vector<int> dfs(int idx)
    {
        if (idx >= nums.size())
            return {};  // Base case: out of bounds

        if (idxToResult.count(idx))
            return idxToResult[idx];  // Return cached result

        vector<int> result;
        result.push_back(nums[idx]);  // Start subset with the current number

        for (int i = idx + 1; i < nums.size(); ++i)
        {
            // Check if nums[i] can be appended to the subset
            if (nums[i] % nums[idx] == 0)
            {
                vector<int> cur = dfs(i);  // Get the subset starting from nums[i]

                vector<int> curRes = { nums[idx] };  // New subset starting with nums[idx]
                curRes.insert(curRes.end(), cur.begin(), cur.end());  // Append the rest

                if (curRes.size() > result.size())
                    result = curRes;  // Update the longest result
            }
        }

        return idxToResult[idx] = result;  // Cache and return result
    }
};