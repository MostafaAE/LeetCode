class Solution 
{
public:
    /**
     * Approach:
     * - First, **sort** the intervals by their start time.
     * - Iterate through the sorted intervals:
     *   - If the current interval **overlaps** with the previous one, merge them.
     *   - Otherwise, store the merged interval and start a new one.
     * - Return the list of merged intervals.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n log n) due to sorting, followed by O(n) for merging, resulting in **O(n log n)** overall.
     * - **Space Complexity**: O(n) for storing merged intervals.
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end()); // Sort intervals based on start time

        vector<vector<int>> mergedIntervals;
        int start = intervals[0][0], end = intervals[0][1], n = intervals.size();

        for (int i = 1; i < n; ++i) 
        {
            int left = intervals[i][0], right = intervals[i][1];

            if (start <= left && left <= end) // Merge overlapping intervals
            {
                end = max(end, right);
            } 
            else // Add the merged interval and start a new one
            {
                mergedIntervals.push_back({start, end});
                start = left;
                end = right;
            }
        }

        mergedIntervals.push_back({start, end}); // Add the last merged interval
        return mergedIntervals;
    }
};