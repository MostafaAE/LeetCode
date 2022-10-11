class Solution {
public:
    
    // Time Complexity: O(nlogn)
    bool containsDuplicate(vector<int>& nums) 
    {
        // O(nlogn)
        sort(nums.begin(), nums.end());
        // O(n)
        for(int i = 1 ; i < (int)nums.size() ; i++)
        {
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};