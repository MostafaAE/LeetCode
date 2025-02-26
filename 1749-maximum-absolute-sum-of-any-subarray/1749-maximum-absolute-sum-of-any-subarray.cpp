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
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int maxSum{}, minSum{}, curMaxSum{}, curMinSum{};

        for(int num : nums)
        {
            if(curMaxSum < 0)
                curMaxSum = 0;

            if(curMinSum > 0)
                curMinSum = 0;

            curMaxSum += num;
            curMinSum += num;
            maxSum = max(maxSum, curMaxSum);
            minSum = min(minSum, curMinSum);
        }
        
        return max(maxSum, abs(minSum));
    }
};