class Solution {
public:
    int maximumXOR(vector<int>& nums) 
    {
        int result{};

        for(int num : nums)
            result |= num;

        return result;
    }
};