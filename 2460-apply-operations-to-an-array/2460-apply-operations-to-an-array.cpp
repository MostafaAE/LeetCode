class Solution {
public:
    /**
     * Approach:
     * 1. Modify the array in-place:
     *    - If two consecutive nonzero numbers are equal, double the first and set the second to zero.
     * 2. Move all nonzero elements to the left (stable order):
     *    - Use a pointer `idx` to track the position for placing nonzero elements.
     *    - Iterate through the array, swapping nonzero elements into their correct position.
     * 
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(1)
     */
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n = nums.size(), idx = 0;

        // Step 1: Modify the array according to the rules
        for (int i = 0; i < n - 1; ++i)
        {
            if (nums[i] != 0 && nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
                ++i;  // Skip the next element since it's set to zero
            }
        }

        // Step 2: Move all nonzero elements to the left
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != 0)
            {
                swap(nums[idx], nums[i]);
                ++idx;
            }
        }
        
        return nums;
    }
};
