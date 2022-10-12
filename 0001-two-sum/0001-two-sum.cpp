class Solution {
public:
    
    // Time Complexity = O(n^2)
    // Space Complexity = O(1)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < (int)nums.size() - 1; i++)
        {
            int diff = target - nums[i];
            for (int j = i + 1; j < (int)nums.size(); j++)
            {
                if (nums[j] == diff)
                    return {j, i};
            }
        }
        return {-1, -1};
    }
};