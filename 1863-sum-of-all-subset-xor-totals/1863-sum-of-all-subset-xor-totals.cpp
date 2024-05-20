class Solution {
public:
    /*
    * Approach:
    * - Use a backtracking approach to explore all subsets of the given array.
    * - For each element in the array, we have two choices: include it in the current subset or exclude it.
    * - We maintain a running XOR result for the current subset being considered.
    * - When we reach the end of the array, we return the XOR result of the current subset.
    * - Sum up the results of all subsets to get the final answer.
    *
    * Complexity:
    * - Time Complexity: O(2^n), where n is the number of elements in the array. (There are 2^n possible subsets)
    * - Space Complexity: O(n), for the recursive stack space.
    */
    int subsetXORSum(vector<int>& nums) 
    {
        return backtrack(nums, 0, 0);
    }
    
    int backtrack(vector<int>& nums, int idx, int xorResult)
    {   
        if (idx >= nums.size())
            return xorResult;
        
        // Include the current element in the subset
        int pick = backtrack(nums, idx + 1, xorResult ^ nums[idx]);
        
        // Exclude the current element from the subset
        int leave = backtrack(nums, idx + 1, xorResult);
        
        // Return the sum of results from both choices
        return pick + leave;
    }
};
