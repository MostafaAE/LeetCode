class Solution 
{
public:
    /**
     * Approach:
     * - Use **binary search** to find the maximum number of candies each child can get.
     * - The search space is from `1` to `10^7` (the maximum possible candies per pile).
     * - For each middle value in the search, check if it's possible to distribute `mid` candies per child to `k` children.
     * - If possible, increase `mid` (move right); otherwise, decrease `mid` (move left).
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n log C), where `n` is the number of candy piles and `C = 10^7` is the max candies per pile.
     * - **Space Complexity**: O(1), as only a few extra variables are used.
     */
    int maximumCandies(vector<int>& candies, long long k) 
    {
        int start = 1, end = 1e7, result{};

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(isPossibleToAllocateCandies(candies, mid, k))
            {
                start = mid + 1;
                result = mid;
            }
            else
            {
                end = mid - 1;
            }
        }

        return result;
    }

private:
    /**
     * Checks if it's possible to distribute `count` candies per child to at least `k` children.
     */
    bool isPossibleToAllocateCandies(vector<int>& candies, int count, long long k)
    {
        long long childrenCount{};

        for(int candy : candies)
        {
            childrenCount += candy / count; // Count how many children can receive `count` candies
        }

        return childrenCount >= k;
    }
};
