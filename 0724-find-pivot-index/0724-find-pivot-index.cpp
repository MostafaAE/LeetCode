class Solution {
public:
    /*
     * Approach
     * Iterate through the array, maintaining running prefix and suffix sums for each index and checking if they are equal.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    int pivotIndex(vector<int>& nums) 
    {
        int suffixSum = accumulate(nums.begin(), nums.end(), 0), prefixSum{};
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            suffixSum -= nums[i];
            
            if(prefixSum == suffixSum)
                return i;
            
            prefixSum += nums[i];
        }
        
        return -1;
    }
};