class Solution {
private:
    const static int MAX = 300 + 1 + 2; // 2 for two extra values we add
    int memory[MAX][MAX];
    vector<int> nums;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Range pattern
     *
     * Complexity:
     * Time Complexity : O(N^3)
     * Space Complexity : O(N^2) where N is the max index
     */
    int maxCoins(vector<int>& _nums) 
    {
        nums = _nums;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        memset(memory, -1, sizeof(memory));
        return burstBallons(1, (int)nums.size()-2);
    }
    
    int burstBallons(int startIdx, int endIdx)
    {
        // invalid range
        if(startIdx > endIdx)
            return 0;
        
        int &ret = memory[startIdx][endIdx];
        if(ret != -1)
            return ret;
        
        ret = INT_MIN;
        for(int k = startIdx ; k <= endIdx ; k++)
        {
            int coins = nums[startIdx-1] * nums[k] * nums[endIdx+1];
            
            // Now K should be fixed and next sub-calls don't use our LAST baloon
            int leftCoins = burstBallons(startIdx, k - 1);
            int rightCoins = burstBallons(k + 1, endIdx);
            
            ret = max(ret, coins + leftCoins + rightCoins);
        }
        
        return ret;
    }
};