class Solution 
{
public:
    /**
     * Approach:
     * - Use **binary search** to find the minimum possible eating speed.
     * - The search space is from `1` to `10^9` (maximum possible banana pile size).
     * - For each middle value in the search, check if Koko can finish all bananas in `h` hours.
     * - If possible, move left to find a smaller speed; otherwise, move right.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n log M), where `n` is the number of piles and `M = 10^9` (max pile size).
     * - **Space Complexity**: O(1)
     */
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int start = 1, end = 1e9, result{};

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(isPossibleToEatAllBananas(piles, mid, h))
            {
                end = mid - 1; // Try a smaller speed
                result = mid;
            }
            else
            {
                start = mid + 1; // Increase speed
            }
        }

        return result;
    }

private:
    /**
     * Checks if Koko can finish all bananas in `h` hours with `speed` bananas per hour.
     */
    bool isPossibleToEatAllBananas(vector<int>& piles, int speed, int h)
    {
        long long hours{}; 

        for(int pile : piles)
        {
            hours += pile / speed + (pile % speed != 0);
        }

        return hours <= h;
    }
};
