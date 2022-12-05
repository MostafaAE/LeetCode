class Solution {
public:
    /* 
    * Approach:
    * Sort the array then keep picking the greedy choice to minimuze the score
    * 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    int smallestRangeII(vector<int>& nums, int k) 
    {
        // O(nlogn)
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int res = nums[n-1] - nums[0];
        
        // O(n)
        for(int i = 0 ; i < n-1 ; i++)
        {
            // at each step minimize the gap
            int high = max(nums[i]+k, nums[n-1]-k);
            int low = min(nums[i+1]-k, nums[0]+k);
            res = min(res, high - low);
        }
        return res;
    }
};