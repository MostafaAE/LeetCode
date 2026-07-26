class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<>());
        
        int totalReductions{};
        for(int i = 1 ; i < n ; ++i)
            if(nums[i] != nums[i-1])
                totalReductions += i;

        return totalReductions;
    }
};