/*
 * Approach:
 * - We are given `n` meeting rooms and a list of meetings with start and end times.
 * - We want to assign each meeting to a room such that:
 *     1. If multiple rooms are available, pick the one with the lowest index.
 *     2. If no rooms are available, delay the meeting until the earliest room becomes free.
 * - After assigning all meetings, we return the room index with the most meetings.
 *
 * Time Complexity:
 * - O(m log n), where m is the number of meetings and n is the number of rooms.
 *   - Each meeting processes heap operations taking O(log n) time.
 *
 * Space Complexity:
 * - O(n), for storing heap of occupied rooms, available rooms, and the meetings count.
 */

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        int meetingsSize = meetings.size();
        sort(meetings.begin(), meetings.end());  // Sort meetings by start time

        // Min-heap: (end time, room index)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupiedRooms;
        // Min-heap of available room indices
        priority_queue<int, vector<int>, greater<>> availableRooms;
        // Count of meetings held by each room
        vector<int> roomsMeetings(n, 0);

        // Initially, all rooms are available
        for (int i = 0; i < n; ++i)
            availableRooms.push(i);

        for (int i = 0; i < meetingsSize; ++i)
        {
            int start = meetings[i][0], end = meetings[i][1];

            // Free rooms that have finished before or at the current meeting's start
            while (!occupiedRooms.empty() && start >= occupiedRooms.top().first)
            {
                auto [time, idx] = occupiedRooms.top();
                occupiedRooms.pop();
                availableRooms.push(idx);
            }

            if (availableRooms.empty())
            {
                // Delay the meeting until the next available room is free
                auto [time, idx] = occupiedRooms.top();
                occupiedRooms.pop();

                // Update end time and push back to occupiedRooms
                occupiedRooms.push({time + end - start, idx});
                ++roomsMeetings[idx];
            }
            else
            {
                // Assign the meeting to the lowest indexed available room
                int idx = availableRooms.top();
                availableRooms.pop();

                occupiedRooms.push({end, idx});
                ++roomsMeetings[idx];
            }
        }

        // Find the room with the most meetings
        int maxIdx = 0;
        for (int i = 1; i < n; ++i)
        {
            if (roomsMeetings[i] > roomsMeetings[maxIdx])
                maxIdx = i;
        }

        return maxIdx;
    }
};