class Solution {
public:
    /**
     * Approach:
     * - If the array size is less than or equal to 4, return 0 since we can remove all elements.
     * - Sort the array.
     * - The minimum difference is achieved by removing three elements in one of the following ways:
     *   - Remove the three smallest elements.
     *   - Remove the two smallest and the largest element.
     *   - Remove the smallest and the two largest elements.
     *   - Remove the three largest elements.
     * - Iterate through the array and calculate the minimum difference for these cases.
     *
     * Complexity:
     * - Time Complexity: O(n logn)
     * - Space Complexity: O(1)
     */
    int minDifference(vector<int>& nums) 
    {
        int n = nums.size();

        // If there are 4 or fewer elements, we can remove all of them, resulting in a difference of 0.
        if(n <= 4)
            return 0;
        
        // Sort the array to easily find the smallest and largest elements.
        sort(nums.begin(), nums.end());
        
        int minDiff = INT_MAX;

        for (int left = 0, right = n - 4; left < 4; left++, right++) 
            minDiff = min(minDiff, nums[right] - nums[left]);

        return minDiff;
    }
};
