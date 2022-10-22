class Solution {
public:
    /* 
    * Approach:
    * binary search: find the lower bound and upper bound of the target
    * 
    * Complexity:
    * Time Complexity : O(logn)
    * Space Complexity : O(1)
    */
    vector<int> searchRange(vector<int>& nums, int target) 
    {
       
        int start = lower_bound(nums, target);
        int end = upper_bound(nums, target);
        
        if(start == end)
            return {-1, -1};
        
        return {start, end-1};
        
    }
    
    int lower_bound(vector<int> &nums, int target)
    {
        int start{}, end{(int)nums.size() - 1};

        while (start <= end)
        {
            // prevent overflow
            int mid = start + (end - start) / 2;

            if (target <= nums[mid])
                end = mid - 1;

            else
                start = mid + 1;
        }

        return start;
    }

    int upper_bound(vector<int> &nums, int target)
    {
        int start{}, end{(int)nums.size() - 1};

        while (start <= end)
        {
            // prevent overflow
            int mid = start + (end - start) / 2;

            if (target < nums[mid])
                end = mid - 1;

            else
                start = mid + 1;
        }

        return start;
    }
};