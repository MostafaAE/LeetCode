class Solution {
public:
    /* 
    * Approach:
    * Use a hashtable to mark visited values, so when we visit equal values we can check the condition of abs(i - j) <= k
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> valToIdx;
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            if(valToIdx.count(nums[i]) && i - valToIdx[nums[i]] <= k)
                return true;
            
            valToIdx[nums[i]] = i;
        }
        
        return false; 
    }
};