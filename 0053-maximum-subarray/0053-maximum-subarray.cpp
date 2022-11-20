class Solution {
public:
    /* 
    * Approach:
    * Kadane's Algorithm
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int maxSubArray(vector<int>& nums) 
    {
        int maxSoFar{INT_MIN}, maxEndingHere{0};
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            maxEndingHere += nums[i];
            
            if(maxSoFar < maxEndingHere)
                maxSoFar = maxEndingHere;
            
            if(maxEndingHere < 0)
                maxEndingHere = 0;
        }
        
        return maxSoFar;
    }
};