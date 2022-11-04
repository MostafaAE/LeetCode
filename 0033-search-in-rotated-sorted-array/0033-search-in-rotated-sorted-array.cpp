class Solution {
public:
    
    /* 
    * Approach:
    * find the minimum value index to decice either to binary search on the left or right on it
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int search(vector<int>& nums, int target) 
    {
        int minIdx = findMinIdx(nums);
        int start{}, end{(int)nums.size()-1};
        
        if(target >= nums[minIdx] && target <= nums[end])
            start = minIdx;
        else
            end = minIdx-1;
        
        return binarySearch(nums, target, start, end);
    }
    
    
   /*
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int findMinIdx(vector<int>& nums) 
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
        
        return start;
    }
    
   /* 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int binarySearch(vector<int>& nums, int target, int start, int end) 
    {
        while(start <= end)
        {
            int mid = start + (end-start) / 2;
            
            if(target == nums[mid])
                return mid;
            
            else if (target < nums[mid])
                end = mid-1;
            
            else
                start = mid+1;
        }
            
        return -1;
    }
};