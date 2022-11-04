class Solution {
public:
    /* 
    * Approach:
    * binary search: find out the mid point and decide to either search on the left or right
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int findMin(vector<int>& nums) 
    {
        int start{}, end{(int)nums.size()-1};
        
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] > nums[end])
                start = mid + 1;
            else
                end = mid;
        }
        
        return nums[start];
    }
};