class Solution {
public:
    /* 
    * Approach:
    * keep searching for the "values" in the hashset until no more found
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int findFinalValue(vector<int>& nums, int original) 
    {
        unordered_set<int> s(nums.begin(), nums.end());
        
        while(s.count(original))
            original *= 2;
        
        return original;
    }
};