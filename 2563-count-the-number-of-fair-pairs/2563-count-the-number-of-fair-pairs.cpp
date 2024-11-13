class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        int n = nums.size();
        long long result{};
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < n ; ++i)
        {
            auto lb = lower_bound(nums.begin(), nums.end(), lower-nums[i]);
            auto up = upper_bound(nums.begin(), nums.end(), upper-nums[i]);
            
            int idx1 = lb - nums.begin();
            int idx2 = up - nums.begin();
            
            if(idx1 <= i)
                idx1 = i + 1;

            result += max(idx2 - idx1, 0);
        }
        
        return result;
    }
};