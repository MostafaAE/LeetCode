class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> um;
        
        for(int i =  0 ; i < (int)nums.size() ; i++)
        {
            if(um.count(nums[i]) && i - um[nums[i]] <= k)
                return true;
            um[nums[i]] = i;
        }
        return false;
    }
};