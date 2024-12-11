class Solution {
public:
    /**
     * Approach:
     * 1. Use a frequency array `count` to track the range increments:
     *    - For each number `num` in `nums`, increment the frequency at `max(0, num - k)`.
     *    - Decrement the frequency at `num + k + 1` (if within bounds) to mark the end of the range.
     * 2. Calculate the prefix sum of the `count` array:
     *    - Traverse the `count` array to compute the cumulative frequency, representing the number of elements in range at each value.
     *    - Track the maximum value of the prefix sum to determine the maximum beauty.
     * 3. Return the maximum beauty found.
     * 
     * Complexity:
     * Time Complexity: O(n + m)
     * - O(n) to process the input array `nums` and update the `count` array.
     * - O(m) to compute the prefix sum, where `m` is the maximum value in `nums` plus `1`.
     * Space Complexity: O(m)
     * - Space required for the frequency array `count` of size `maxVal + 1`.
     */
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int maxVal = *max_element(nums.begin(), nums.end());
        
        vector<int> count(maxVal + 1, 0);
        
        for(int num : nums)
        {
            ++count[max(num - k, 0)];
            if(num + k + 1 <= maxVal)
                --count[num + k + 1];
        }
        
        int result{}, curSum{};
        for(int val : count)
        {
            curSum += val;
            result = max(result, curSum);
        }
        
        return result;
    }
};