class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int n = nums.size(), longestIncSoFar{1}, longestDecSoFar{1};

        int curLongestInc{1}, curLongestDec{1};
        for(int i = 1 ; i < n ; ++i)
        {
            if(nums[i] > nums[i-1])
                ++curLongestInc, curLongestDec = 1;
            else if(nums[i] < nums[i-1])
                ++curLongestDec, curLongestInc = 1;
            else
                curLongestInc = curLongestDec = 1;
            
            longestIncSoFar = max(longestIncSoFar, curLongestInc);
            longestDecSoFar = max(longestDecSoFar, curLongestDec);
        }
        
        return max(longestIncSoFar, longestDecSoFar);
    }
};