class Solution {
public:
    /*
     * Approach:
     * Prefix sum with hashmap
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int n{(int)nums.size()}, count{}, curSum{}, result{};
        unordered_map<int, int> freq;
        
        for(int num : nums)
        {
            curSum += num;
            
            if(curSum == goal)
                result++;
            
            if(freq.count(curSum-goal))
                result += freq[curSum-goal];
            
            freq[curSum]++;
        }
        
        return result;
    }
};