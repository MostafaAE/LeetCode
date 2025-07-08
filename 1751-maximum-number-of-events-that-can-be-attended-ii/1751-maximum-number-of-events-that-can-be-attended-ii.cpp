/*
 * Approach:
 * - First, sort the events based on their start times.
 * - Use recursion + memoization (top-down DP) to explore two choices at each step:
 *   1. Skip the current event → move to the next event.
 *   2. Take the current event → recursively find the next non-overlapping event using binary search.
 * - Store intermediate results in a 2D memoization table: memory[idx][k], 
 *   where `idx` is the current index and `k` is the number of remaining picks.
 * - Use binary search (upperBound) to efficiently find the next event whose start time is after the current event’s end time.
 * 
 * Time Complexity:
 * - Sorting: O(n log n)
 * - DP + Binary Search: O(n * k * log n)
 *     - There are n * k states in the memo table.
 *     - For each state, we do O(log n) for the binary search.
 * 
 * Space Complexity: O(n * k), for memoization table.
 */

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) 
    {
        int n = events.size();
        // memory[i][k] stores the max value we can get starting from index i with k choices left
        vector<vector<int>> memory(n + 1, vector<int>(k + 1, -1));

        // Sort events by start time
        sort(events.begin(), events.end());

        return maxEvents(0, k, events, memory);
    }

    int maxEvents(int idx, int k, vector<vector<int>>& events, vector<vector<int>>& memory)
    {
        if (idx >= (int)events.size() || k == 0)
            return 0;

        if (memory[idx][k] != -1)
            return memory[idx][k];

        // Binary search for the next event that starts after the current event's end time
        int nextIdx = upperBound(events, events[idx][1]);

        // Option 1: take current event and move to next non-overlapping
        int pick = events[idx][2] + maxEvents(nextIdx, k - 1, events, memory);

        // Option 2: skip current event
        int leave = maxEvents(idx + 1, k, events, memory);

        // Store and return the maximum of both options
        return memory[idx][k] = max(pick, leave);
    }

    // Binary search for the first event with start time > target (end of current event)
    int upperBound(vector<vector<int>>& events, int target)
    {
        int left = 0, right = (int)events.size();
        while (left < right) 
        {
            int mid = left + (right - left) / 2;

            if (events[mid][0] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};