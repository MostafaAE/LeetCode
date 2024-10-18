class Solution {
public:
    /**
     * Approach:
     * - First, we calculate the maximum OR value achievable by taking the OR of all elements in the array.
     * - Then, we recursively check each subset of the array, counting how many of them have the same OR value as the maximum.
     * 
     * Complexity:
     * - Time Complexity: O(2^n), where `n` is the size of the input array `nums`. For each element, we have two choices: include it in the subset or exclude it, resulting in 2^n subsets.
     * - Space Complexity: O(n), where `n` is the depth of the recursion stack, which is equal to the size of the array.
     */

    int countMaxOrSubsets(vector<int>& nums) 
    {
        int maxOrValue = 0;
        
        // Step 1: Calculate the maximum OR value of the entire array
        for (int num : nums)
            maxOrValue |= num;

        // Step 2: Use a recursive function to count subsets that achieve this maximum OR value
        return countSubsets(nums, 0, 0, maxOrValue);
    }
    
    // Recursive function to count subsets
    int countSubsets(vector<int>& nums, int index, int currentOr, int targetOr)
    {
        // Base case: If we have considered all elements
        if(index >= nums.size())
            return (currentOr == targetOr) ? 1 : 0; 
        
        // Option 1: Include the current element in the subset (pick)
        int pick = countSubsets(nums, index + 1, currentOr | nums[index], targetOr);
        
        // Option 2: Exclude the current element from the subset (leave)
        int leave = countSubsets(nums, index + 1, currentOr, targetOr); 
        
        // Return the total count from both the pick and leave options
        return pick + leave;
    }
};
