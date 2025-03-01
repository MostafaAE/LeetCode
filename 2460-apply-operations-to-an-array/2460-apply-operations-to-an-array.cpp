class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n = nums.size(), idx{};
        
        for(int i = 0 ; i < n - 1 ; ++i)
        {
            if(nums[i] != 0 && nums[i] == nums[i + 1])
            {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
                ++i;
            }
        }

        for(int i = 0 ; i < n ; ++i)
        {
            if(nums[i] != 0)
            {
                swap(nums[idx], nums[i]);
                ++idx;
            }
        }
        
        return nums;
    }
};