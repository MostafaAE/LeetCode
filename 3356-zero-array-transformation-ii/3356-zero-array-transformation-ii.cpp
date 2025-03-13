class Solution 
{
public:
    /**
     * Approach:
     * - We perform a **binary search** on the minimum number of queries needed to make `nums` a zero array.
     * - The function `isPossibleToAchieveZeroArray(nums, queries, k)` determines if the first `k` queries can achieve this.
     * - We use a **difference array** technique to efficiently apply range updates from the queries.
     * - The binary search ensures we find the **smallest** `k` that makes all elements in `nums` non-positive.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O((n + q) log q)
     *   - `isPossibleToAchieveZeroArray` runs in O(n + k), where `k ≤ q`.
     *   - The binary search runs O(log q) times.
     *   - Overall, O(n log q + q log q) simplifies to O((n + q) log q).
     * - **Space Complexity**: O(n), for the difference array.
     */
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int q = queries.size();
        int start = 0, end = q;

        // If it's impossible to achieve a zero array with all queries, return -1
        if (!isPossibleToAchieveZeroArray(nums, queries, end))
            return -1;

        // Perform binary search to find the minimum number of queries needed
        while (start <= end) 
        {
            int mid = start + (end - start) / 2;

            if (isPossibleToAchieveZeroArray(nums, queries, mid)) 
            {
                end = mid - 1; // Try to minimize k
            } 
            else 
            {
                start = mid + 1; // Increase k
            }
        }

        return start;
    }

private:
    /**
     * Checks if applying the first `k` queries is sufficient to make `nums` non-positive.
     */
    bool isPossibleToAchieveZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) 
    {
        int n = nums.size(), sum{};
        vector<int> diff(n + 1, 0); // Difference array

        // Apply first k queries using difference array technique (O(k))
        for (int i = 0; i < k; ++i) 
        {
            vector<int> v = queries[i];
            diff[v[0]] += v[2];      // Start of the range
            diff[v[1] + 1] -= v[2];  // End of the range
        }

        // Compute the actual prefix sum and check if nums can be made non-positive (O(n))
        for (int i = 0; i < n; ++i) 
        {
            sum += diff[i];
            if (nums[i] > sum) 
            {
                return false;
            }
        }

        return true;
    }
};