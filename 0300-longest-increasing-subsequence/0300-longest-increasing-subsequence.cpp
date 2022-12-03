class Solution {
private:
const static int MAX = 2500 + 1;
int memory[MAX];
    
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick next mask one approach)
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int lengthOfLIS(vector<int>& nums) 
    {
        memset(memory, -1, sizeof(memory));
        nums.insert(nums.begin(), INT_MIN);
        return LIS(nums, 0) - 1;
    } 
    
    int LIS(vector<int>& nums, int idx)
    {
        if (idx == nums.size())
            return 0;
        
        auto &ret = memory[idx];
        if (ret != -1)
            return memory[idx];
        
        ret = 0 ;
        for(int j = idx + 1 ; j < (int)nums.size() ; j++)
            if(nums[idx] < nums[j])
                ret = max(ret, LIS(nums, j));
        
        ret++;
        return ret;
    }
};