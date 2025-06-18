class Solution {
public:
    /*
    * Approach:
    * - Sort the nums array in increasing order.
    * - Process every group of 3 consecutive elements:
    *     - If the difference between the largest and smallest in the triplet (nums[idx + 2] - nums[idx]) exceeds k → return empty array.
    *     - Else, add the valid triplet {nums[idx], nums[idx + 1], nums[idx + 2]} to the result.
    *
    * Time Complexity: O(n log n)
    * Space Complexity: O(log n), for sorting.
    */
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());

        vector<vector<int>> result(n / 3);

        for (int idx = 0, currentBucket = 0; idx < n; idx += 3, ++currentBucket)
        {
            // If the triplet is invalid (diff > k), return empty array
            if (nums[idx + 2] - nums[idx] > k)
                return {};

            // Insert valid triplet into result
            result[currentBucket] = {nums[idx], nums[idx + 1], nums[idx + 2]};
        }

        return result;
    }
};