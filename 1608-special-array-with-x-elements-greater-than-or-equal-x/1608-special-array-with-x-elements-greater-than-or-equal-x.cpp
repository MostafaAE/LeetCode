class Solution {
public:
    /* 
    * Approach:
    * binary search (monotonic function)
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    int specialArray(vector<int>& nums) 
    {
        int start{1}, end{(int)nums.size()}, answer{-1};
        
        // O(nlogn)
        sort(nums.begin(), nums.end());
        
        // O(logn)
        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(greaterEqCount(nums, mid) >= mid)
                start = mid + 1, answer = mid;
            else
                end = mid - 1;
        }
        
        return (greaterEqCount(nums, answer) == answer) ? answer : -1;
    }
    
    int greaterEqCount(vector<int> &nums, int x)
    {
        // O(logn)
        auto lb = lower_bound(nums.begin(), nums.end(), x);
        return distance(lb, nums.end());
    }
};