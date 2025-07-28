/*
 * Approach:
 * 1. First, compute the maximum OR value that can be achieved from any subset.
 * 2. Use recursion with memoization (Top-down DP) to count the number of subsets that achieve this OR value.
 *    At each index, we have two choices:
 *    - Include the current element in the OR
 *    - Skip the current element
 * 3. If the OR at the end of the subset equals the maximum, count it.
 * 4. Use memoization to cache subproblems using index and current OR value.
 *
 * Time Complexity: O(n * maxOrValue)
 * - n = number of elements
 * - maxOrValue = max OR value from all elements
 *
 * Space Complexity: O(n * maxOrValue)
 */

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int maxOrValue = 0;

        for (int num : nums)
            maxOrValue |= num;

        vector<vector<int>> memory(nums.size(), vector<int>(maxOrValue + 1, -1));

        return countSubsets(nums, memory, 0, 0, maxOrValue);
    }
    
private:
    int countSubsets(vector<int>& nums, vector<vector<int>>& memory, int index, int currentOr, const int& targetOr)
    {
        if (index >= nums.size())
            return (currentOr == targetOr) ? 1 : 0;

        if (memory[index][currentOr] != -1)
            return memory[index][currentOr];

        // Option 1: Pick current element
        int pick = countSubsets(nums, memory, index + 1, currentOr | nums[index], targetOr);
        
        // Option 2: Skip current element
        int leave = countSubsets(nums, memory, index + 1, currentOr, targetOr); 
        
        return memory[index][currentOr] = pick + leave;
    }
};