class Solution {
public:
    /**
     * Approach:
     * - Initialize `minSoFar` and `maxSoFar` with the first array's minimum and maximum elements.
     * - Iterate through the remaining arrays and calculate the maximum distance by comparing:
     *   - The difference between the current `maxSoFar` and the first element of the current array.
     *   - The difference between the last element of the current array and `minSoFar`.
     * - Update `minSoFar` and `maxSoFar` accordingly.
     * - The result will be the maximum distance found during the iteration.
     *
     * Complexity:
     * - Time Complexity: O(n), where n is the number of arrays.
     * - Space Complexity: O(1)
     */
    int maxDistance(vector<vector<int>>& arrays) 
    {
        int minSoFar = arrays[0].front(), maxSoFar = arrays[0].back(), result = INT_MIN;
        
        for(int i = 1; i < arrays.size(); ++i)
        {
            // Calculate maximum distance for the current array
            result = max(result, max(maxSoFar - arrays[i].front(), arrays[i].back() - minSoFar));
            
            minSoFar = min(minSoFar, arrays[i].front());
            maxSoFar = max(maxSoFar, arrays[i].back());
        }
        
        return result;
    }
};
