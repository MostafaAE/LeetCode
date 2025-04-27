/**
 * Approach:
 * - Iterate over all subarrays of length 3.
 * - For each triplet (nums[i-2], nums[i-1], nums[i]), check if:
 *   (first + third) * 2 == second
 * - Count how many satisfy this condition.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
 
class Solution {
public:
    int countSubarrays(vector<int>& nums) 
    {
        int n = nums.size(), count{};

        for(int i = 2 ; i < n ; ++i)
        {
            count += (nums[i] + nums[i-2]) * 2 == nums[i-1];
        }

        return count;
    }
};