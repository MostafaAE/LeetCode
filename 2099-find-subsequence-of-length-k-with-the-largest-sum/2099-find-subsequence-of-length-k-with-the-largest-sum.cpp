/*
 * Approach:
 * - We need to return the `k` largest elements from the array *in the same relative order* as the original array.
 * - Use a min-heap (priority_queue) of size `k` to store the top `k` largest elements along with their indices.
 * - If the heap size exceeds `k`, remove the smallest element.
 * - After collecting the top `k` elements, extract their indices and sort them to maintain original order.
 * - Finally, build the result using the stored indices.
 *
 * Time Complexity  : O(n log k) for pushing into the min-heap.
 *                    O(k log k) for sorting the indices.
 *                    O(k) to collect the final result.
 *                    => Overall: O(n log k)
 *
 * Space Complexity : O(k) for storing top elements and indices.
 */

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        int n = nums.size();

        // Min-heap to store {value, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (int i = 0; i < n; ++i)
        {
            if ((int)minHeap.size() < k || nums[i] > minHeap.top().first)
            {
                minHeap.push({nums[i], i});
            }

            if ((int)minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> indices;
        while (!minHeap.empty())
        {
            indices.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // Sort indices to preserve the original order
        sort(indices.begin(), indices.end());

        // Build the final subsequence from sorted indices
        vector<int> result;
        for (int idx : indices)
            result.push_back(nums[idx]);

        return result;
    }
};