class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        int result{}, n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < n ; ++i)
            result = max(result, nums[i]+nums[n-i-1]);
        
        return result;
    }
};