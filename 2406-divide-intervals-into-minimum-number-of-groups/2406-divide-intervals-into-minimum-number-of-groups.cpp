class Solution {
public:
    /**
     * Approach:
     * - The problem is to find the minimum number of groups of intervals such that no two intervals in a group overlap.
     * - First, sort the intervals by their start times to process them in order.
     * - Use a min-heap (priority queue) to track the earliest ending interval in each group.
     * - For each interval:
     *   - If the earliest ending interval (top of the heap) can accommodate the current interval (i.e., it doesn't overlap), update the heap by removing the top element and adding the new interval.
     *   - If the current interval cannot fit into any existing group, increment the group count and push it into the heap.
     * - The min-heap ensures that we always extend the group that ends the earliest.
     * 
     * Complexity:
     * - Time Complexity: O(n logn), where `n` is the number of intervals. Sorting takes O(n log n) and each heap operation is O(log n).
     * - Space Complexity: O(n), since the heap can contain at most `n` intervals in the worst case.
     */
    int minGroups(vector<vector<int>>& intervals) 
    {
        int result{}, n = intervals.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        
        // Sort intervals by their start times
        sort(intervals.begin(), intervals.end());
        
        // Process each interval
        for(int i = 0 ; i < n ; ++i)
        {
            // If the earliest ending group can accommodate this interval, update the heap
            if(!minHeap.empty() && minHeap.top().first <= intervals[i][0])
            {
                minHeap.pop();
                minHeap.push({intervals[i][1]+1, 1e6});
            }
            // Otherwise, create a new group
            else
            {
                ++result;
                minHeap.push({intervals[i][1]+1, 1e6});
            }
        }
        
        return result;
    }
};