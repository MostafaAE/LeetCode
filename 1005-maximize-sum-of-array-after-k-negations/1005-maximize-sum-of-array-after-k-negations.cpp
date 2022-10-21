class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int minVal{INT_MAX}, sum{};
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            if(k > 0 && nums[i] < 0)
            {
                nums[i] = -nums[i];
                k--;
            }
            sum+= nums[i];
            minVal = min(minVal, nums[i]);
        }
        
        if(k%2)
            sum-= 2*minVal;
        
        return sum;
    }
};