class Solution 
{
public:
    /**
     * Approach:
     * - First, **sort** the intervals based on their start times.
     * - Iterate through the sorted intervals:
     *   - If the current interval does **not overlap** with the last merged interval, add it to the result.
     *   - Otherwise, merge it by updating the end time of the last interval.
     * - Return the list of merged intervals.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n log n) due to sorting, followed by O(n) for merging, resulting in **O(n log n)** overall.
     * - **Space Complexity**: O(n) for storing the merged intervals.
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end()); // Sort intervals based on start time

        vector<vector<int>> merged;
        for (auto interval : intervals) 
        {
            if (merged.empty() || merged.back()[1] < interval[0]) // No overlap, add new interval
            {
                merged.push_back(interval);
            }
            else // Overlap, merge intervals
            {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        
        return merged;
    }
};
