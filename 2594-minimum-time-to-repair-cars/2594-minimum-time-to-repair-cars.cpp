class Solution {
public:
    /**
     * Approach:
     * - We use **Binary Search** on the minimum possible time required to repair all cars.
     * - The total time taken by a mechanic with rank `r` to repair `n` cars follows the formula:  
     *   **time = r * n²** → **n = sqrt(time / r)**
     * - Given a time `t`, we check if all `cars` can be repaired by summing up `sqrt(t / rank)` for each mechanic.
     * - We perform binary search on time from **1** to **max_rank * cars²**.
     * - The function `isPossibleToRepairAllCarsInTime` determines if a given time `t` is feasible.
     * - We minimize the feasible time using binary search.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(k * log(maxRank * n²)), where k i ranks size, n is cars count.
     *   - Binary search runs in **O(log(maxRank * n²))**.
     *   - Checking feasibility (`isPossibleToRepairAllCarsInTime`) takes **O(k)**.
     * - **Space Complexity**: O(1)
     */
    long long repairCars(vector<int>& ranks, int cars) 
    {
        long long maxRank = *max_element(ranks.begin(), ranks.end());

        // Binary search range: minimum time = 1, maximum time = maxRank * cars²
        long long start = 1, end = maxRank * cars * cars, result = end;

        while(start <= end)
        {
            long long mid = start + (end - start) / 2;

            if(isPossibleToRepairAllCarsInTime(ranks, cars, mid))
            {
                result = mid; // Update minimum feasible time
                end = mid - 1; // Search in the lower half
            }
            else
            {
                start = mid + 1; // Search in the upper half
            }
        }

        return result;
    }

private:
    /**
     * Checks if it's possible to repair all cars within the given time.
     * Uses the formula: **carsRepaired = sum(sqrt(time / rank))** for all mechanics.
     * Returns `true` if at least `cars` can be repaired, otherwise `false`.
     */
    bool isPossibleToRepairAllCarsInTime(vector<int>& ranks, int cars, long long time)
    { 
        long long carsRepaired = 0;
        for(int rank : ranks)
        {
            carsRepaired += sqrt(time / rank); // Number of cars a mechanic can repair

            if(carsRepaired >= cars)
                return true; // Stop early if condition met
        }

        return false;
    }
};
