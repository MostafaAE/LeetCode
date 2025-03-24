class Solution {
public:
    /**
     * Approach:
     * - **Sort the meetings** by start day to process them in order.
     * - Add a **dummy meeting** `{days + 1, days + 1}` to simplify handling the last gap.
     * - Traverse the sorted meetings:
     *   - If there's a gap between the `endDay` (last meeting's end) and the `start` of the current meeting, 
     *     add the gap to the `result`.
     *   - Update `endDay` to track the latest occupied day.
     * - Return `result`, which represents the count of free days.
     *
     * Complexity Analysis:
     * - **Time Complexity**: O(N log N), where `N` is the number of meetings.
     *   - Sorting takes **O(N log N)**.
     *   - The single pass through the meetings takes **O(N)**.
     * - **Space Complexity**: O(1), as sorting is done in-place, and only a few extra variables are used.
     */
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        meetings.push_back({days + 1, days + 1}); // Dummy meeting to handle last gap
        sort(meetings.begin(), meetings.end());   // Sort meetings by start day

        int result = 0, endDay = 0;

        for (auto& meeting : meetings)
        {
            int start = meeting[0], end = meeting[1];

            if (start > endDay)
            {
                result += start - endDay - 1; // Count free days between meetings
            }

            endDay = max(endDay, end); // Extend the latest occupied day
        }

        return result;
    }
};