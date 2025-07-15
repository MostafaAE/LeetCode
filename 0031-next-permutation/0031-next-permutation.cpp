/*
 * Approach:
 * 1. Traverse from right to left to find the first pair where nums[i] < nums[i + 1]. Let's call this index the pivot.
 * 2. If no such pivot exists, the array is the highest permutation. Reverse the entire array.
 * 3. Otherwise, find the rightmost element greater than nums[pivot], and swap them.
 * 4. Finally, reverse the suffix starting at pivot + 1 to get the next smallest lexicographic permutation.
 *
 * Time Complexity  : O(n), where n is the size of the array.
 * Space Complexity : O(1), in-place operations.
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int pivotIndex = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (pivotIndex >= 0 && nums[pivotIndex] >= nums[pivotIndex + 1]) 
        {
            --pivotIndex;
        }

        // Step 2: If pivot is found, find the next greater element to the right
        if (pivotIndex >= 0) 
        {
            int successorIndex = n - 1;

            // Find the element just larger than nums[pivotIndex]
            while (nums[successorIndex] <= nums[pivotIndex])
            {
                --successorIndex;
            }

            // Swap pivot with successor
            swap(nums[pivotIndex], nums[successorIndex]);
        }

        // Step 3: Reverse the suffix starting from pivotIndex + 1
        reverse(nums.begin() + pivotIndex + 1, nums.end());
    }
};