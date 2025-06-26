/*
 * Approach:
 * Use a max-heap (priority_queue) of size `k` to keep track of the k closest points to the origin.
 * 
 * - For each point, compute its squared Euclidean distance from the origin.
 * - If the heap size is less than `k`, or the current distance is smaller than the maximum in the heap,
 *   push it into the heap.
 * - If the heap size exceeds k, remove the farthest point (top of the max-heap).
 * - After processing all points, extract the indices from the heap and use them to build the result.
 *
 * Time Complexity  : O(n log k), where n is the number of points.
 *                    Each insertion/removal from the heap is O(log k), and we do this n times.
 * Space Complexity : O(k), for maintaining the max-heap.
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        int n = points.size();
        // Max-heap to store {distance, index} of the closest k points
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < n; ++i)
        {
            // Compute squared distance to avoid sqrt
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];

             // Insert if heap has fewer than k elements or distance is smaller than current maximum
            if(maxHeap.size() < k || distance < maxHeap.top().first)
                maxHeap.push({distance, i});

            // Remove farthest if size exceeds k
            if ((int)maxHeap.size() > k)
                maxHeap.pop();
        }

        // Collect results from heap
        vector<vector<int>> result;
        while (!maxHeap.empty())
        {
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return result;
    }
};