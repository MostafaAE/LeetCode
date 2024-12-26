class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> result(2*n);
        
        for(int i = 0 ; i < n ; ++i)
            result[i] = result[i + n] = nums[i];
        
        return result;
    }
};