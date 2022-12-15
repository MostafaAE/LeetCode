class Solution {
private:
    const static int MAX_IDX = 100 + 1;
    int memory[MAX_IDX];
    vector<int> nums;
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization (Pick or Leave approach)
    * 
    * Complexity:
    * Time Complexity : O(N)
    * Space Complexity : O(N)
    */
    int rob(vector<int>& _nums) 
    {
        nums = _nums;
        memset(memory, -1, sizeof(memory));
        return robber(0);
    }
    
    int robber(int idx)
    {
        if(idx >= nums.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        int rob = nums[idx] + robber(idx+2);
        int skip = robber(idx+1);
        
        return ret = max(rob, skip);
    }
};