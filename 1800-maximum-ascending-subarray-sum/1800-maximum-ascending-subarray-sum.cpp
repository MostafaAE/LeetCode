class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        int n = nums.size(), maxSum{nums[0]}, curMax{nums[0]};

        for(int i = 1 ; i < n ; ++i)
        {
            if(nums[i] > nums[i-1])
                curMax += nums[i];
            else
                curMax = nums[i];
            
            maxSum = max(maxSum, curMax);
        }

        return maxSum;
    }
};