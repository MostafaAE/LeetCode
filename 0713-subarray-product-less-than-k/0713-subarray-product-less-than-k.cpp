class Solution {
public:
    /* 
    * Approach:
    * Sliding window
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if(k <= 1)
            return 0;
        
        int count{}, left{}, product{1};
        
        for(int right = 0 ; right < (int)nums.size() ; right++)
        {
            product *= nums[right];
            while(product >= k)
                product /= nums[left++];
            
            count += right - left + 1;
        }
        
        return count;
    }
};