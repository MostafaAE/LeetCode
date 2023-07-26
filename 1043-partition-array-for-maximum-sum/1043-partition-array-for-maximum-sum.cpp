const int MAX = 500 + 1;
int memory[MAX], maxLength;
vector<int> arr;
class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization
     * 
     * Direct Consecutive range pattern
     * We want to find a good array split
     *
     * dp(idx)
     *  Try all consecutive ranges as long as subarrays length < k
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int maxSumAfterPartitioning(vector<int>& arr_, int k) 
    {
        maxLength = k;
        arr = arr_;
        memset(memory, -1, sizeof(memory));
        
        return maxSum(0);
    }
    
    int maxSum(int index)
    {
        if(index >= (int)arr.size())
            return 0;
        
        int &ret = memory[index];
        if(ret != -1)
            return ret;
        
        ret = INT_MIN;
        int maxVal{INT_MIN}, len{};
        for(int split = index ; len < maxLength && split < (int)arr.size() ; split++)
        {
            len++;
            maxVal = max(maxVal, arr[split]);
            
            int blockSum = len * maxVal;
            ret = max(ret, blockSum + maxSum(split + 1));
        }
        
        return ret;
    }
};