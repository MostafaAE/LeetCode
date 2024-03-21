class Solution {
public:
    /* 
    * Approach:
    * First, find the min positive integer in the array, if it is > 1, then the answer is 1,
    * If the min positive integer = 1, then perform cycle sort, then iterate on the array to find
    * the first value where value != index + 1 (first missing positive)
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int firstMissingPositive(vector<int>& nums) 
    {
        int minPositive{INT_MAX}, n{(int)nums.size()};

        for(int num : nums)
            if(num > 0)
                minPositive = min(minPositive, num);
        
        if(minPositive != 1)
            return 1;
        
        // apply cycle sort
        int i{};
        while(i < n)
        {
            int correctIdx = nums[i];
            if(correctIdx > 0 && correctIdx <= n && nums[i] != nums[correctIdx-1])
                swap(nums[i], nums[correctIdx-1]);
            else
                i++;
        }
        
        i = 0;
        while(i < n)
        {
            if(nums[i] != i + 1)
                return i + 1;
            i++;
        }
        
        return i + 1;
    }
};