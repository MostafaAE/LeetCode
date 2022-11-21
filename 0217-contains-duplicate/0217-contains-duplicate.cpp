class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
            if(!s.insert(nums[i]).second)
                return true;
        
        return false;
    }
};