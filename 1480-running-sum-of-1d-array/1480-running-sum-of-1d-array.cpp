class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1) >> neglecting the output space
    */
    vector<int> runningSum(vector<int>& nums) 
    {
        vector<int> result;
        int sum{};
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
            sum += nums[i], result.push_back(sum);
        
        return result;
        
    }
};