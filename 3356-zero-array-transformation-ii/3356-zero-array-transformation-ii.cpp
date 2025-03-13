class Solution 
{
public:
    /**
     * Approach:
     * - We iterate through `nums` and attempt to reduce each element to zero using the queries.
     * - A **difference array** is used to efficiently apply range updates from the queries.
     * - If `nums[idx] > sum + difference[idx]`, we need more queries to make it zero.
     * - We track the number of applied queries (`queryIdx`) and ensure we do not exceed `q`.
     * - The final answer is the **minimum number of queries** needed to achieve the goal.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n + q), since we iterate through `nums` once and apply at most `q` queries.
     * - **Space Complexity**: O(n), for the difference array.
     */
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size(), q = queries.size(), queryIdx{}, sum{};
        vector<int> difference(n + 1, 0); // Difference array to handle range updates efficiently

        for (int idx = 0; idx < n; ++idx) 
        {
            while (nums[idx] > sum + difference[idx]) 
            {
                ++queryIdx;

                // If we have used more queries than available, it's impossible
                if (queryIdx > q)
                    return -1;

                int left = queries[queryIdx - 1][0], right = queries[queryIdx - 1][1], val = queries[queryIdx - 1][2];

                // Apply the query only if it affects the current index
                if (right >= idx) 
                {
                    difference[max(left, idx)] += val; // Apply increase at the start of the range
                    difference[right + 1] -= val;      // Reverse at the end of the range
                }
            }
            
            sum += difference[idx]; // Update sum with the difference array value
        }

        return queryIdx;
    }
};