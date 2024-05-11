class Solution {
public:
    /* 
    * Approach:
    * - Similar to (153. Find Minimum in Rotated Sorted Array) but with duplicates.
    * - When num[mid] == num[end], we can't make sure that the position of minimum in mid's left or right, so just let upper bound reduce one.
    * - So in worst case (all duplicates) the time complexity will be O(n)
    * - But in average case it will be a normal binary search O(logn)
    */
    int findMin(vector<int>& nums) 
    {
        int start{}, end{(int)nums.size()-1};
        
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] > nums[end])
                start = mid + 1;
            else if (nums[mid] < nums[end])
                end = mid;
            else
                end--;
        }
        
        return nums[start];
    }
};