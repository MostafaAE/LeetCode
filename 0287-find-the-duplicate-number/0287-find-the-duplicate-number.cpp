class Solution {
public:
    /*
     * Approach:
     * Use a hash table to check if a number is repeated.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    int findDuplicate(vector<int>& nums) 
    {
        unordered_set<int> hashSet;
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
            if(!hashSet.insert(nums[i]).second)
                return nums[i];
        
        return 0;
        
    }
};