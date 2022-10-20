class Solution {
public:
    /* 
    * Approach:
    * Binary search
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
            int mid = (start+end)/2;
            
            if(target == nums[mid])
                return mid;
            
            if(target < nums[mid])
                end = mid-1;
            
            else
                start = mid+1;
        }
        return start;
        
    }
};