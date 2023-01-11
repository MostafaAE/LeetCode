class Solution {
private:
    static const int MAX = 1000 + 1;
    int memory[MAX];
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
     * Space Complexity : O(MN) where M is the max target, and N is the max index
     */
    int combinationSum4(vector<int>& _nums, int target) 
    {
        memset(memory, -1 , sizeof(memory));
        nums = _nums;
        return combSum(target);
    }
    
    int combSum(int target)
    {
        // not valid
        if(target < 0)
            return 0;
        
        // valid way
        if(target == 0)
            return 1;
        
        int &ret = memory[target];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int i = 0 ; i < (int)nums.size() ; i++)
            ret += combSum(target - nums[i]);
    
        return ret;
    }
};