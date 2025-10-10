class Solution {
public:
    int alternatingSum(vector<int>& nums) 
    {
        int sum = 0;

        for(int i = 0 ; i < nums.size() ; ++i)
        {
            if(i & 1)
                sum -= nums[i];
            else
                sum += nums[i];
        }

        return sum;
    }
};