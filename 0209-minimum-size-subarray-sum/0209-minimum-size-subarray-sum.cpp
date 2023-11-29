class Solution {
public:
    
    /* 
    * Approach:
    * Iterate over the array with a variable size sliding window
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen{INT_MAX}, currentSum{}, windowSize{};
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            currentSum += nums[i];
            windowSize++;
            
            while(currentSum >= target)
            {
                minLen = min(minLen, windowSize);
                currentSum -= nums[i+1 - windowSize--];
            }
                
        }
        
        return minLen == INT_MAX ? 0 : minLen;
        
    }
};