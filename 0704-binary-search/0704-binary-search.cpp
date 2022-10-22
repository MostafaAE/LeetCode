class Solution {
public:
    /* 
    * Approach:
    * basic binary search algorithm
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int search(vector<int>& nums, int target) 
    {
        int start{}, end{(int)nums.size()-1};
        
        while(start <= end)
        {
            // prevent overflow
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