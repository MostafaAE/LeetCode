const int MAX = 2500 + 1;
int memory[MAX][MAX];
vector<int> nums;
class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N^2) where N is the max index
     */
    int lengthOfLIS(vector<int>& nums_) 
    {
        nums = nums_;
        memset(memory, -1, sizeof(memory));
        return LIS(0, (int)nums.size());
    }
    
    int LIS(int idx, int prev)
    {
        if(idx >= (int)nums.size())
            return 0;
        
        int &ret = memory[idx][prev];
        if(ret != -1)
            return ret;
        
        // leave
        int leave = LIS(idx + 1, prev);
        
        // pick
        int pick{};
        if(prev >= (int)nums.size() || nums[prev] < nums[idx])
            pick = 1 + LIS(idx + 1, idx);
        
        return ret = max(leave, pick);
    }
};