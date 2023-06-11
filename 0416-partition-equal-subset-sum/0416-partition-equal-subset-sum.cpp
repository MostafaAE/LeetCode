const int MAX_LEN = 200 + 1, MAX_SUM = 100 * 100 + 1;
int memory[MAX_LEN][MAX_SUM];
vector<int> nums;
class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick or leave approach)
     *
     * Complexity:
     * Time Complexity : O(NM)
     * Space Complexity : O(NM) where N is the max index and M is the max sum
     */
    bool canPartition(vector<int>& nums_) 
    {
        int sum = accumulate(nums_.begin(), nums_.end(), 0);
        
        if(sum&1)
            return false;
        
        memset(memory, -1, sizeof(memory));
        nums = nums_;
        return isSubsetSum(0, sum/2);
    }
    
    bool isSubsetSum(int idx, int rem)
    {
        if(!rem)
            return true;
        
        // can't find a combination
        if(idx >= (int)nums.size())
            return false;
        
        int &ret = memory[idx][rem];
        if(ret != -1)
            return ret;
        
        // pick
        bool pick{};
        if(nums[idx] <= rem)
            pick = isSubsetSum(idx + 1, rem - nums[idx]);
        
        // leave
        bool leave = isSubsetSum(idx + 1, rem);
        
        return ret = pick || leave;
        
    }
};