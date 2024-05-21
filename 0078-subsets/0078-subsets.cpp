class Solution {
public:
    /*
    * Approach:
    * - Use a backtracking approach to generate all subsets of the given array.
    * - For each element in the array, we have two choices: include it in the current subset or exclude it.
    * - Recursively explore both choices and add the resulting subsets to the final result.
    * - When we reach the end of the array, add the current subset to the result.
    *
    * Complexity:
    * - Time Complexity: O(2^n * n), where n is the number of elements in the array.
    *   - There are 2^n possible subsets.
    *   - Generating each subset takes O(n) time in the worst case (for copying the subset).
    * - Space Complexity: O(n)
    */
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> curSubset;
        
        generateSubsets(0, nums, curSubset, result);
        
        return result;
    }
    
    void generateSubsets(int idx, vector<int>& nums, vector<int>& curSubset, vector<vector<int>>& res)
    {
        if(idx >= nums.size())
        {
            res.push_back(curSubset);
            return;
        }
        
        // we have 2 choices
        
        // 1. pick the current number
        curSubset.push_back(nums[idx]);
        generateSubsets(idx + 1, nums, curSubset, res);
        
        // 2. leave the current number
        curSubset.pop_back();
        generateSubsets(idx + 1, nums, curSubset, res);
    }
};