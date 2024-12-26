class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int result{};
        for(auto num : nums)
            result += num % 3 != 0;
        
        return result;
    }
};