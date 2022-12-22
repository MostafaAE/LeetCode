class Solution {
private:
    static const int MAX = 500 + 1;
    int memory[MAX], k;
    vector<int> arr;
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
    int maxSumAfterPartitioning(vector<int>& _arr, int _k) 
    {
        arr = _arr;
        k = _k;
        memset(memory, -1, sizeof(memory));
        return partition(0);
    }
    
    int partition(int idx)
    {
        if(idx >= (int)arr.size())
            return 0;
        
        int &ret = memory[idx];
        if(ret != -1)
            return ret;
        
        ret = 0;
        int maxVal{};
        for(int endIdx = idx ; endIdx < idx + k && endIdx <(int)arr.size() ; endIdx++)
        {
            maxVal = max(maxVal, arr[endIdx]);
            int len = endIdx - idx + 1;
            int sum = maxVal * len + partition(idx+len);
            ret = max(ret, sum);
        }
        return ret;
    }
};