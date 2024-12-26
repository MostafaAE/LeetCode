class Solution {
private:
    int count{};
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        backtrack(nums, 0, 0, target);
        return count;
        
    }
    
    void backtrack(vector<int>& nums, int idx, int sum, int target)
    {
        if(idx >= nums.size())
        {
            if(sum == target)
                ++count;
            return;
        }
        
        backtrack(nums, idx + 1, sum + nums[idx], target);
        backtrack(nums, idx + 1, sum - nums[idx], target);
    }
};