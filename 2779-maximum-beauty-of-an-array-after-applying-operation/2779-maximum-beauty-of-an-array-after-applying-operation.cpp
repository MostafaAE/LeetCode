class Solution {
public:
    /**
     * Approach:
     * 1. Sort the array `nums`.
     * 2. Iterate through each element in the array:
     *    - For each element `nums[i]`, find the first element greater than `nums[i] + 2*k` using `upper_bound`.
     *    - Compute the beauty for this range as the distance between the current index and the iterator from `upper_bound`.
     *    - Update the result to store the maximum beauty found so far.
     * 3. Return the maximum beauty value.
     * 
     * Complexity:
     * Time Complexity: O(n log n)
     * - Sorting the array takes O(n log n).
     * - For each of the `n` elements, `upper_bound` takes O(log n), resulting in O(n log n) for all queries.
     * Space Complexity: O(1)
     */
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int n = nums.size(), result{};
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < n ; ++i)
        {
            auto itr = upper_bound(nums.begin(), nums.end(), nums[i] + 2*k);
            
            int curBeauty = distance(nums.begin() + i, itr);
            
            result = max(result, curBeauty);
        }
        
        return result;
    }
};