class Solution 
{
public:
    /*
    * Approach:
    * - We want to count valid pairs of points (a, b) such that:
    *       a.x <= b.x   AND   a.y >= b.y
    *   (basically "a" is top-left relative to "b").
    *
    * Steps:
    * 1. Sort the points by:
    *      - x ascending
    *      - if tie, y descending
    *    This ensures for each point `b`, all candidate `a` are before it.
    *
    * 2. For each point i (treat as `b`):
    *      - Iterate backward through points j < i.
    *      - We maintain an `oldY` tracker to avoid double-counting.
    *      - Condition: points[j].y >= points[i].y AND points[j].y < oldY
    *          → If true, we count (j, i) as a valid pair.
    *          → Update oldY to prevent counting another point with y ≥ i.y but not stricter.
    *
    * Time Complexity: O(n^2)
    * Space Complexity: O(1)
    */
    int numberOfPairs(vector<vector<int>>& points) 
    {
        int n = points.size(), count = 0;

        // Sort by x asc, y desc
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) 
                return a[1] > b[1];  // for equal x, sort by y descending
            return a[0] < b[0];
        });
        
        for (int i = n - 1; i >= 1; --i)
        {
            int x = points[i][0], y = points[i][1];
            int oldY = INT_MAX;

            for (int j = i - 1; j >= 0; --j)
            {
                if (points[j][1] >= y && points[j][1] < oldY)
                {
                    ++count;
                    oldY = points[j][1];
                }
            }
        }

        return count;
    }
};