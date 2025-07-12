/*
 * Approach:
 * To maximize performance, we want to select at most `k` engineers such that:
 * Performance = sum_of_speeds * min_efficiency.
 *
 * Strategy:
 * - Sort engineers by efficiency in descending order.
 * - Iterate through engineers, and at each step:
 *     - Consider current engineer's efficiency as the minimum for the team.
 *     - Maintain a min-heap to keep the top `k` speeds (remove smallest if heap exceeds size k).
 *     - Calculate performance using current sum of speeds and current efficiency.
 *     - Update result accordingly.
 *
 * Time Complexity: O(n log n)
 * - Sorting: O(n log n)
 * - Each insertion/removal in the heap: O(log k) over `n` iterations → O(n log k)
 * - Total: O(n log n)
 *
 * Space Complexity: O(n)
 * - For the heap and auxiliary vectors
 */

using ll = long long;

class Solution {
private:
    static const int MOD = 1e9 + 7;

public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<pair<int, int>> efficiencyToSpeed;
        priority_queue<int, vector<int>, greater<>> minHeap;

        // Pair each engineer's efficiency with their speed
        for (int i = 0; i < n; ++i)
            efficiencyToSpeed.push_back({efficiency[i], speed[i]});

        // Sort by efficiency in descending order
        sort(efficiencyToSpeed.begin(), efficiencyToSpeed.end(), greater<>());

        ll curSum = 0, result = 0;

        // Iterate through engineers sorted by efficiency
        for (int i = 0; i < n; ++i)
        {
            auto [e, s] = efficiencyToSpeed[i];
            curSum += s;

            // If we already have k speeds, remove the smallest one
            if ((int)minHeap.size() >= k)
            {
                curSum -= minHeap.top();
                minHeap.pop();
            }

            // Calculate performance and update result
            result = max(result, curSum * e);

            // Push current speed to heap
            minHeap.push(s);
        }

        return result % MOD;
    }
};