class Solution {
public:
    /* 
    * Approach:
    * find the leftmost and rightmost elements from the unsorted
    * continious subarray and return the distance between them
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int left{-1}, right{-1}, size{(int)nums.size()};
        
        // find the rightmost element in the unsorted continuous subarray
        // O(n)
        int maxVal{nums[0]};
        for(int i = 1 ; i < size ; i++)
        {
            if(nums[i] < maxVal)
                right = i;
            
            maxVal = max(maxVal, nums[i]);
        }
        
        // find the leftmost element in the unsorted continuous subarray
        // O(n)
        int minVal{nums[size-1]};
        for(int i = size-2 ; i >= 0 ; i--)
        {
            if(nums[i] > minVal)
                left = i;
            
            minVal = min(minVal, nums[i]);
        }
        if(right == -1)
            return 0;
        
        return right - left + 1;
        
    }
};