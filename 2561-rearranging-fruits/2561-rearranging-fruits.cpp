/*
 * Approach:
 * 1. Count the imbalance of each item between both baskets using a hash map.
 *    - If the count of any item is odd, return -1 (can't make them equal).
 * 2. For each imbalance (diff > 0 or diff < 0), collect half the excess of each item into a vector `merge`.
 *    - Because each swap fixes 2 items, we divide the absolute imbalance by 2.
 * 3. Sort the `merge` vector (represents items to fix).
 * 4. The cheapest fix for each mismatch is either:
 *    - Direct swap: use the smaller value.
 *    - Indirect swap: swap both items through two swaps with the global minimum value.
 *    - So we take min(merge[i], 2 * globalMin) for the first half of the `merge` vector.
 *
 * Time Complexity: O(n log n)
 *   - One pass for counting (O(n)), one sort on imbalanced values (O(n log n)).
 *
 * Space Complexity: O(n)
 *   - To store frequency counts and mismatch items.
 */

class Solution 
{
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        int n = basket1.size();
        int globalMin = INT_MAX;
        unordered_map<int, int> valToCount;

        // Step 1: Build imbalance map and track global minimum value
        for (int i = 0; i < n; ++i)
        {
            ++valToCount[basket1[i]];
            --valToCount[basket2[i]];
            globalMin = min(globalMin, min(basket1[i], basket2[i]));
        }

        // Step 2: Gather mismatch values
        vector<int> merge;
        for (auto [val, count] : valToCount)
        {
            // If imbalance is odd, we can't make baskets equal
            if (count & 1)
                return -1;

            // Push half the imbalance (each swap fixes 2 elements)
            for (int i = 0; i < abs(count) / 2; ++i)
                merge.push_back(val);
        }

        // Step 3: Sort the imbalance values
        sort(merge.begin(), merge.end());

        // Step 4: Compute minimum cost to fix mismatches
        long long result = 0;
        int halfSize = merge.size() / 2;

        for (int i = 0; i < halfSize; ++i)
        {
            // Either swap the value directly or use two swaps with the global min
            result += min(merge[i], 2 * globalMin);
        }

        return result;
    }
};