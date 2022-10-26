class Solution {
public:
    /* 
    * Approach:
    * find lower bound of the target
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    int searchInsert(vector<int>& nums, int target) 
    {
        int start{}, end{(int)nums.size()-1};
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            
            if(target <= nums[mid])
                end = mid - 1; 
            
            else
                start = mid + 1;   
        }
        return start;
        
    }
};