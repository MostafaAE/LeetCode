class Solution {
private:
const static int MAX = 2500 + 1;
int memory[MAX][MAX];
    
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N^2) where N is the max index
     */
    int lengthOfLIS(vector<int>& nums) 
    {
        memset(memory, -1, sizeof(memory));
        return LIS(nums, 0, nums.size());
    } 
    
    int LIS(vector<int>& nums, int idx, int prevIdx)
    {
        if (idx == nums.size())
            return 0;
        
        auto &ret = memory[idx][prevIdx];
        if (ret != -1)
            return memory[idx][prevIdx];

        int pick{}, leave{};
        if (prevIdx == nums.size() || nums[idx] > nums[prevIdx])
            pick = 1 + LIS(nums, idx + 1, idx);

        leave = LIS(nums, idx + 1, prevIdx);
        
        return ret = max(pick, leave);
    }
};