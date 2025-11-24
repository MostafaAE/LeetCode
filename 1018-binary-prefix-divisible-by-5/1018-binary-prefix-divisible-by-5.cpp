class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) 
    {
        vector<bool> result;
        int prefix = 0;
        for(int num : nums)
        {
            prefix = ((prefix << 1) + num) % 5;
            result.push_back(prefix == 0);
        }

        return result;
    }
};