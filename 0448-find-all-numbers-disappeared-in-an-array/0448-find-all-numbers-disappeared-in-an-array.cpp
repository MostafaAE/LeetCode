class Solution {
public:
    /* 
    * Approach:
    * Iterate over nums, for each value we find mark it as found by multiplying the value in its index by -1.
    *
    * Another approach is to use a frequency array to count the occurrence of each number but will be O(n) space complexity.
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) => ignoring output space
    */
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n{(int)nums.size()};
        vector<int> result;
        
        for(int i = 0 ; i < n ; i++)
        {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0)
                nums[idx] *= -1;
        }

        for(int i = 0 ; i < n ; i++)
            if(nums[i] > 0)
                result.push_back(i+1);

        return result;
    }
};