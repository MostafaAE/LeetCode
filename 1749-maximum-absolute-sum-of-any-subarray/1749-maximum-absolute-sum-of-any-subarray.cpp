class Solution {
public:
    /* 
    * Approach:
    * Get both the maximum sum subarray and the minimum sum subarray and return the max absolute of them
    * Note: use Kadane's algorithm to get the maximum sum and minumim sum subarray to make the alogithm O(n)
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(maxSum(nums)), abs(minSum(nums)));
    }
    
    int maxSum(vector<int>& nums)
    {
        int maxSoFar{}, maxSum{INT_MIN};
        
        for(int n : nums)
        {
            maxSoFar += n;
            maxSum = max(maxSum , maxSoFar);
            
            if(maxSoFar < 0)
                maxSoFar = 0;
        }
        return maxSum;
    }
    
    int minSum(vector<int>& nums)
    {
        int minSoFar{}, minSum{INT_MAX};
        
        for(int n : nums)
        {
            minSoFar += n;
            minSum = min(minSum , minSoFar);
            
            if(minSoFar > 0)
                minSoFar = 0;
        }
        return minSum;
    }
};