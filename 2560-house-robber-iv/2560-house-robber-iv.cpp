class Solution 
{
public:
    /**
     * Approach:
     * - Use **binary search** on the minimum capability required to rob `k` houses.
     * - The search space is from `1` to `max(nums)`, as the worst case requires robbing any house.
     * - For each middle value in the search, check if we can rob `k` houses while following the rule (no two adjacent houses).
     * - If possible, move left to find a smaller capability; otherwise, move right.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n log M), where `n` is the number of houses and `M = max(nums)`.
     * - **Space Complexity**: O(1)
     */
    int minCapability(vector<int>& nums, int k) 
    {
        int start = 1, end = *max_element(nums.begin(), nums.end()), result = end;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(isPossibleToRobKHouses(nums, mid, k))
            {
                end = mid - 1; // Try a smaller capability
                result = mid;
            }
            else
            {
                start = mid + 1; // Increase capability
            }
        }

        return result;
    }

private:
    /**
     * Checks if it is possible to rob `k` houses with `capability` without robbing adjacent houses.
     */
    bool isPossibleToRobKHouses(vector<int>& nums, int capability, int k)
    {
        int robbedCount{}, n = nums.size();
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(nums[i] <= capability)
            {
                ++robbedCount;
                ++i; // Skip the next house to prevent adjacent robbery
            }
        }

        return robbedCount >= k;
    }
};
