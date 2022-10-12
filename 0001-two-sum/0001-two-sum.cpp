class Solution {
public:
    
    // Time Complexity = O(n)
    // Space Complexity = O(n)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> um;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (um.count(nums[i]))
                return {um[nums[i]], i};

            um[target - nums[i]] = i;
        }

        return {-1, -1};
    }
};