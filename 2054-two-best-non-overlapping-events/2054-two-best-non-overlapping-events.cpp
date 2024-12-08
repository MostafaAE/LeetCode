class Solution {
public:
    /**
     * Approach:
     * 1. Sort the events by their start time to process them in chronological order.
     * 2. Use a priority queue to keep track of events that have ended. Each entry in the queue is a pair of `{end_time, value}`.
     * 3. Traverse the sorted events:
     *    - For the current event, remove events from the priority queue where the end time is less than the start time of the current event (these events cannot overlap with the current event).
     *    - Update `maxVal` to store the highest value of non-overlapping events processed so far.
     *    - Calculate the maximum sum of values by considering the current event's value and `maxVal`.
     *    - Add the current event to the priority queue.
     * 4. Return the maximum sum (`maxSum`) obtained during the traversal.
     * 
     * Complexity:
     * Time Complexity: O(n log n)
     * - O(n log n) for sorting the events.
     * - O(n log n) for priority queue operations (push and pop for `n` events).
     * Space Complexity: O(n)
     * - Space for the priority queue, which can hold up to `n` events.
     */
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        sort(events.begin(), events.end());

        int maxVal = 0, maxSum = 0;

        for (auto& event : events) 
        {
            // Remove non-overlapping events
            while (pq.size() && pq.top().first < event[0]) 
            {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            // Update the maximum sum considering the current event
            maxSum = max(maxSum, maxVal + event[2]);
            pq.push({event[1], event[2]});
        }

        return maxSum;
    }
};
