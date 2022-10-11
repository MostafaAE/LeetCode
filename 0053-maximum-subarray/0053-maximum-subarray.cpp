class Solution {
public:
    
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = nums[0], curSum = nums[0];
        for(int i = 1 ; i < (int)nums.size() ; i++)
        {
            if(curSum < 0)
                curSum = 0;
            
            curSum += nums[i];
            
            if(curSum > maxSum)
                maxSum = curSum;
        }
        return maxSum;
    }
};