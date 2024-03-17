class Solution {
public:
    /*
     * Approach:
     * Iterate over the intervals array, we have 3 cases
     * Case 1: no overlapping before the new interval
     * Case 2: overlapping intervals
     * Case 3: no overlapping after the new interval
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1) => ignoring the output space
     */
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int n{(int)intervals.size()}, idx{};
        vector<vector<int>> result;
        
        // Case 1: no overlapping before the new interval
        // interval comes before the new interval
        while(idx < n && intervals[idx][1] < newInterval[0])
            result.push_back(intervals[idx]), idx++;
        
        // Case 2: overlapping case
        // interval end overlap with the new interval
        // interval start overlap with the new interval
        // cur interval completely overlap new interval
        while(idx < n && intervals[idx][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        result.push_back(newInterval);
        
        // Case 3: no overlapping after new interval
        // current interval comes after the new interval
        while(idx < n)
            result.push_back(intervals[idx]), idx++;

        return result;
    }
};