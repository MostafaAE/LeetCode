class Solution {
public:
    
    // Time Complexity: O(n)
    // Memory Complexity: O(n)
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> s;
        
        // O(n)
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            // insert() method takes O(1).
            if(!s.insert(nums[i]).second)
                return true;
        }
        return false;
    }
};