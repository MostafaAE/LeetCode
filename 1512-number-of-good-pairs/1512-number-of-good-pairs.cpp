class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        int result{};
        unordered_map<int, int> valToCount;
        
        for(int num : nums)
        {
            result += valToCount[num];
            ++valToCount[num];
        }
        
        return result;
    }
};