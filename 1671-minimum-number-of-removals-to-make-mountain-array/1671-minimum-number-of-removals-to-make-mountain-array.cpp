class Solution {
private:
    const static int MAX = 1000 + 1;
    int memoryLIS[MAX];
    int memoryLDS[MAX];
    vector<int> nums;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick next mask one approach)
     * Just like the LIS Problem
     * For each index find the longest increasing subsequence starting from start to index
     * and find the longest decreasing subsequence starting from index to the end.
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int minimumMountainRemovals(vector<int>& _nums) 
    {
        nums = _nums;
        int sz = (int)nums.size();
        memset(memoryLIS, -1, sizeof(memoryLIS));
        memset(memoryLDS, -1, sizeof(memoryLDS));
        
        int mountainSize{};
        for(int i = 0 ; i < sz ; i++)
        {
            if(LISFromStart(i) == 1 || LDSToEnd(i) == 1)
                continue;
            
            int cur = LISFromStart(i) + LDSToEnd(i) - 1;
            mountainSize = max(mountainSize, cur);
        }
            
        
        return sz - mountainSize;
    }
    
    int LISFromStart(int index)
    {
        if(index <= -1)
            return 0;
        
        int &ret = memoryLIS[index];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int j = index -1 ; j >= 0 ; j--)
            if(nums[j] < nums[index])
                ret = max(ret, LISFromStart(j));
        ret++;
        return ret;
    }
    
    int LDSToEnd(int index)
    {
        if(index >= (int)nums.size())
            return 0;
        
        int &ret = memoryLDS[index];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int j = index + 1 ; j < (int)nums.size() ; j++)
            if(nums[j] < nums[index])
                ret = max(ret, LDSToEnd(j));
        ret++;
        return ret;
    }
};