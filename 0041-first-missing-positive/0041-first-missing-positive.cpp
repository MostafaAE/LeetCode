class Solution {
public:
    /* 
    * Approach:
    * Perform cycle sort on positive values between 1 and n, then iterate on the array to find the first value where value != index + 1 (first missing positive)
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int firstMissingPositive(vector<int>& nums) 
    {
        int n{(int)nums.size()};

        // apply cycle sort
        int idx{};
        while(idx < n)
        {
            int correctPos = nums[idx];
            if(correctPos > 0 && correctPos <= n && nums[idx] != nums[correctPos-1])
                swap(nums[idx], nums[correctPos-1]);
            else
                idx++;
        }
        
        // find the first value where value != index + 1 (first missing positive)
        idx = 0;
        while(idx < n)
        {
            if(nums[idx] != idx + 1)
                return idx + 1;
            idx++;
        }
        
        return idx + 1;
    }
};