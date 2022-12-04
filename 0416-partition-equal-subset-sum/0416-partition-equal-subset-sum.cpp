class Solution {
private:
const static int MAX_IDX = 200, MAX_SUM = 10000 + 1;
int memory[MAX_IDX][MAX_SUM];
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick or leave approach)
     *
     * Complexity:
     * Time Complexity : O(NM)
     * Space Complexity : O(NM) where N is the max index and M is the max sum
     */
    bool canPartition(vector<int>& nums) 
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        memset(memory, -1, sizeof(memory));
        
        // if the sum is odd then we can't partition
        if(totalSum&1)
            return false;
        
        // return if we can partition
        return subsetSum(nums, 0, totalSum/2);
    }
    
    bool subsetSum(vector<int>& values, int idx, int remainingSum)
    {
        if (remainingSum < 0)
            return false;

        if (remainingSum == 0)
            return true;

        // can't find a combination
        if (idx == values.size())
            return false;

        auto &ret = memory[idx][remainingSum];
        if (ret != -1)
            return ret;

        // leave this value
        if (subsetSum(values, idx + 1, remainingSum))
            return ret = true;

        // pick this value
        return ret = subsetSum(values, idx + 1, remainingSum - values[idx]);
    }
};