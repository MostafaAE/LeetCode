class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) 
    {
        int n = nums.size();
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        vector<int> result(n);
        for(int i = 0 ; i < n ; ++i)
        {
            rightSum -= nums[i];
            result[i] = abs(leftSum - rightSum);
            leftSum += nums[i];
        }

        return result;
    }
};