class Solution {
private:
    static const int MAX = 1001;
    int memory[MAX];
    vector<int> nums;
public:
    /*
     * Approach:
     * - Top-down Dynamic Programming with memoization.
     * - Try each number in `nums` and subtract it from the target.
     * - Recursively find the number of ways to build up the remaining target.
     * - Order matters in this problem (permutations), unlike the coin change problem.
     *
     * Time Complexity : O(M * N), where M = target, N = nums.size()
     * Space Complexity : O(M) for the memoization array
     */
    int combinationSum4(vector<int>& nums, int target) 
    {
        memset(memory, -1 , sizeof(memory));
        this->nums = nums;
        return combSum(target);
    }
    
    // Count permutations that sum up to `remaining`
    int combSum(int remaining)
    {
        if (remaining < 0)
            return 0;  // Not a valid combination

        if (remaining == 0)
            return 1;  // Found a valid combination

        int &ret = memory[remaining];
        if (ret != -1)
            return ret;

        ret = 0;
        for (int i = 0 ; i < (int)nums.size() ; i++)
        {
            ret += combSum(remaining - nums[i]);
        }

        return ret;
    }
};