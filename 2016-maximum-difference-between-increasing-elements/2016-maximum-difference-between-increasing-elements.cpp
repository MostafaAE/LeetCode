class Solution {
public:
    /* 
    * Approach:
    * Keep track of the min element visited while traversing
    * 
    * Complexity:
    * Time Complexity : O(N)
    * Space Complexity : O(1)
    */
    int maximumDifference(vector<int>& nums) {
        int maxDiff{INT_MIN}, n{(int)nums.size()}, minVal{nums[0]};
        
        for(int i = 1 ; i < n ; i++)
        {
            maxDiff = max(maxDiff, nums[i] - minVal);
            if(nums[i] < minVal)
                minVal = nums[i];
        }
        
        return maxDiff > 0 ? maxDiff : -1;
        
    }
};