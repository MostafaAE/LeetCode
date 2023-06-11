const int MAX = 2500 + 1;
int memory[MAX];
vector<int> nums;
class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick next mask one approach)
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int lengthOfLIS(vector<int>& nums_) 
    {
        nums = nums_;
        memset(memory, -1, sizeof(memory));
        nums.insert(nums.begin(), INT_MIN);
        return LIS(0) - 1;
    }
    
    int LIS(int idx)
    {
        if(idx >= (int)nums.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int i = idx + 1 ; i < (int)nums.size() ; i++)
            if(nums[i] > nums[idx])
                ret = max(ret, LIS(i));
        
        ret++;
        return ret;
    }
};