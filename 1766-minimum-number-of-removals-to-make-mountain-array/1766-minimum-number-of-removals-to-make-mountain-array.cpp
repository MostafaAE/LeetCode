const int MAX = 1000 + 1;
int memoryLIS[MAX];
int memoryLDS[MAX];
vector<int> numsg;

class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (pick next mask one approach)
     * Just like the LIS Problem
     * Find the longest increasing subsequence starting from start to index
     * and find the longest decreasing subsequence starting from index to the end.
     *
     * Complexity:
     * Time Complexity : O(N^2)
     * Space Complexity : O(N) where N is the max index
     */
    int minimumMountainRemovals(vector<int>& nums) 
    {
        numsg = nums;
        int sz = (int)numsg.size();
        memset(memoryLIS, -1, sizeof(memoryLIS));
        memset(memoryLDS, -1, sizeof(memoryLDS));

        int mountainSize{};
        for(int i = 0 ; i < sz ; i++)
        {
            int LISLength = LIS(i);
            int LDSLength = LDS(i);
            
            if(LISLength == 1 || LDSLength == 1)
                continue;

            int curMountainSize = LISLength + LDSLength - 1;
            mountainSize = max(mountainSize, curMountainSize);
        }

        return sz - mountainSize;
    }

    int LIS(int idx) 
    {
        if(idx <= -1)
            return 0;
        
        int &ret = memoryLIS[idx];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int i = idx - 1; i > -1 ; i--)
            if(numsg[i] < numsg[idx])
                ret = max(ret, LIS(i));
        ret++;
        return ret;
    }

    int LDS(int idx) 
    {
        if(idx >= (int)numsg.size())
            return 0;
        
        int &ret = memoryLDS[idx];
        if(ret != -1)
            return ret;
        
        ret = 0;
        for(int i = idx + 1; i < (int)numsg.size() ; i++)
            if(numsg[i] < numsg[idx])
                ret = max(ret, LDS(i));
        ret++;
        return ret;
    }
};