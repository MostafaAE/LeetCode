/*
 * Approach:
 * We want to attend the maximum number of non-overlapping events, where each event can only be attended on a single day within its start and end range.
 * 
 * Steps:
 * 1. Sort the events by their start day.
 * 2. Use a min-heap (priority_queue with `greater`) to keep track of event end times available on the current day.
 * 3. Iterate day-by-day:
 *    - First, remove any events that have already expired (their end day < current day).
 *    - If the heap is empty and there are still events left, skip to the next event's start day.
 *    - Push all events that start today into the heap.
 *    - Attend the event that ends earliest (min-heap top), and remove it from the heap.
 * 
 * Time Complexity  : O(n log n), where n is the number of events.
 *                    - Sorting takes O(n log n).
 *                    - Each event is pushed and popped from the heap at most once (O(log n) per operation).
 * Space Complexity : O(n), for the heap and sorting.
 */

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        int n = events.size(), result = 0;

        // Min-heap to store the end times of the available events
        priority_queue<int, vector<int>, greater<>> minHeap;

        // Sort events by start time
        sort(events.begin(), events.end());

        for (int day = 1, eventIdx = 0; eventIdx < n || !minHeap.empty(); ++day)
        {
            // Remove events whose end day has already passed
            while (!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();

            // If no available events and more are remaining, jump to the next event's start day
            if (minHeap.empty() && eventIdx < n)
                day = max(day, events[eventIdx][0]);

            // Add all events starting today to the heap
            while (eventIdx < n && events[eventIdx][0] == day)
            {
                minHeap.push(events[eventIdx][1]);
                ++eventIdx;
            }

            // Attend the event with the earliest end day
            if (!minHeap.empty())
            {
                ++result;
                minHeap.pop();
            }
        }

        return result;
    }
};