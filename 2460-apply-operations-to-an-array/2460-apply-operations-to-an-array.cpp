class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n = nums.size(), idx{};

        nums.push_back(0);
        vector<int> result(n, 0);
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(nums[i] != 0 && nums[i] != nums[i+1])
            {
                result[idx++] = nums[i];
            }
            else if(nums[i] != 0 && nums[i] == nums[i + 1])
            {
                result[idx++] = nums[i] * 2;
                ++i;
            }
        }
        
        return result;
    }
};