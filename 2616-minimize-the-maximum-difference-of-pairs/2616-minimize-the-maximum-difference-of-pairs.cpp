class Solution {
public:
    /*
     * Approach:
     * - Sort the input array.
     * - Use binary search on the range of possible maximum differences.
     * - For a given threshold (mid), check if we can form at least `p` pairs
     *   such that the difference between elements in a pair is <= threshold.
     *   - If possible, try to minimize further (search left).
     *   - Otherwise, search right.
     *
     * Time Complexity: O(n log n + n log(max_diff))
     * Space Complexity: O(1)
     */
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int left = 0;
        int right = nums[n - 1] - nums[0];
        int result = INT_MAX;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            // If we can form at least p valid pairs with max diff <= mid
            if (hasValidPairs(nums, mid, p))
            {
                result = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }

private:
    // Greedily checks if at least p valid pairs can be formed
    bool hasValidPairs(vector<int>& nums, int threshold, int p) 
    {
        int index = 0;
        int count = 0;

        while (index < nums.size() - 1) 
        {
            // If the pair is valid, count it and skip the next element
            if (nums[index + 1] - nums[index] <= threshold) 
            {
                ++count;
                index++;  // skip next to ensure non-overlapping
            }

            ++index;
        }

        return count >= p;
    }
};