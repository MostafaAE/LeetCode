class Solution {
private:
    static const int MAXIDX = 200 + 1, MAXAMOUNT = 1000 + 1;
    int memory[MAXIDX][MAXAMOUNT];
    vector<int> nums;
    
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Counting DP
     *
     * Complexity:
     * Time Complexity : O(MN)
     * Space Complexity : O(MN)
     */
    int combinationSum4(vector<int>& _nums, int target) 
    {
        memset(memory, -1 , sizeof(memory));
        nums = _nums;
        return combSum(0, target);
    }
    
    int combSum(int idx, int target)
    {
        // not valid
        if(target < 0)
            return 0;
        
        // valid way
        if(target == 0)
            return 1;
        
        int &ret = memory[idx][target];
        if(ret != -1)
            return ret;
        
        
        ret = 0;
        for(int i = 0 ; i < (int)nums.size() ; i++)
            ret += combSum(i, target - nums[i]);
    
        return ret;
    }
};