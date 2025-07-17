class Solution {
public:
    int maximumLength(vector<int>& nums, int k) 
    {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int maxLen = 0;
        
        for (int num : nums) 
        {
            for (int j = 0; j < k; ++j) 
            {
                int remainder = num % k;
                maxLen = max(maxLen, dp[remainder][j] = dp[j][remainder] + 1);
            }
        }
        
        return maxLen;
    }
};