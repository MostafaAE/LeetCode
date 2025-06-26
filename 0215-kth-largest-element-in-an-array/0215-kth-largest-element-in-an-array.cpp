/*
 * Approach:
 * To find the k-th largest element, we use a min-heap of size `k`.
 * 
 * - Traverse the array and maintain a min-heap with at most `k` elements.
 * - For each number, insert it into the heap.
 * - If the heap size exceeds `k`, remove the smallest element (heap top).
 * - After processing all numbers, the top of the min-heap will be the k-th largest element.
 *
 * Time Complexity  : O(n log k), where n is the number of elements in the array.
 *                    Each insertion/deletion in the heap takes O(log k).
 * Space Complexity : O(k), for storing at most `k` elements in the heap.
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (int num : nums)
        {
            minHeap.push(num);

            // Remove the smallest if we have more than k elements
            if (minHeap.size() > k)
                minHeap.pop();
        }

        // The top of the heap is the k-th largest element
        return minHeap.top();
    }
};