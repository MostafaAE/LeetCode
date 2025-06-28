/*
 * Approach:
 * - Store all points using a map from x-coordinate to a set of y-coordinates: `xToYs[x] = set of y's`.
 * - Iterate over all pairs of points (i, j).
 * - For each pair, treat them as diagonal corners of a potential rectangle.
 *   - If the points are not aligned (i.e., x1 != x2 and y1 != y2), then check whether the other two corners
 *     of the rectangle exist: (x1, y2) and (x2, y1).
 *   - This check is fast because we can look them up in `xToYs` using `unordered_set::count`.
 * - If all four corners exist, compute the area and update the minimum area seen so far.
 *
 * Time Complexity  : O(n^2), where n is the number of points.
 *                    - There are O(n^2) pairs of points.
 *                    - Each lookup for the opposite corners is O(1) on average due to hash set.
 *
 * Space Complexity : O(n), for storing x → set of y coordinates in a hash map.
 */

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) 
    {
        int n = points.size();

        // Map from x-coordinate to all y-values at that x
        unordered_map<int, unordered_set<int>> xToYs;
        for (const auto& p : points)
        {
            int x = p[0], y = p[1];
            xToYs[x].insert(y);
        }

        int result = INT_MAX;

        // Check all pairs of points
        for (int i = 0; i < n - 1; ++i)
        {
            int x1 = points[i][0], y1 = points[i][1];

            for (int j = i + 1; j < n; ++j)
            {
                int x2 = points[j][0], y2 = points[j][1];

                // Skip if they lie on the same line (no rectangle can be formed)
                if (x1 == x2 || y1 == y2)
                    continue;

                // Check if the other two corners exist
                if (xToYs[x1].count(y2) && xToYs[x2].count(y1))
                {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    result = min(result, area);
                }
            }
        }

        return result == INT_MAX ? 0 : result;
    }
};