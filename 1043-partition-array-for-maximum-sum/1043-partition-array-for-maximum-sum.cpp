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
        for(int i = 0 ; i < k && idx+i <(int)arr.size() ; i++)
        {
            maxVal = max(maxVal, arr[idx+i]);
            int sum = maxVal * (i+1) + partition(idx+i+1);
            ret = max(ret, sum);
        }
        return ret;
    }
};