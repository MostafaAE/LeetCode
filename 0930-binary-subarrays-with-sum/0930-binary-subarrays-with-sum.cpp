class Solution {
public:
    /*
     * Approach:
     * Sliding window technique.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n{(int)nums.size()}, zerosCount{}, result{}, curSum{};
        
        
        for(int right = 0, left = 0 ; right < n ; right++)
        {
            curSum += nums[right];
            
            // Count the prefix zeros and reduce the sum if it exceeds the goal
            while(left < right && (curSum > goal || nums[left] == 0))
            {
                if(nums[left])
                    zerosCount = 0;
                else
                    zerosCount++;
                
                curSum -= nums[left++];
            }
            
            if(curSum == goal)
                result += 1 + zerosCount;
        }
        return result;
    }
};