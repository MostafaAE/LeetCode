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
        int maxSoFar{INT_MIN}, maxEndingHere{};
        
        for(int val : nums)
        {
            maxEndingHere += val;
            
            maxSoFar = max(maxSoFar, maxEndingHere);
            
            if(maxEndingHere < 0)
                maxEndingHere = 0;
        }
        
        return maxSoFar;
    }
};