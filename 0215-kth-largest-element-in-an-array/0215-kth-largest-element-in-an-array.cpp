/*
 * Approach:
 * Use a min-heap of size `k` to track the k largest elements from the array.
 * 
 * - Iterate over each number in the array.
 * - If the heap size is less than `k`, or the current number is larger than the smallest in the heap,
 *   push it into the heap.
 * - If the heap exceeds size `k`, pop the smallest element.
 * - After processing all elements, the top of the min-heap will hold the k-th largest element.
 *
 * Time Complexity  : O(n log k), where n is the number of elements in the array.
 *                    Insertion and removal from the heap is O(log k), and we do this at most n times.
 * Space Complexity : O(k), for maintaining the min-heap.
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        // Min-heap to maintain the k largest elements
        priority_queue<int, vector<int>, greater<>> minHeap;

        for (int num : nums)
        {
            // Insert if heap has fewer than k elements or num is greater than current minimum
            if ((int)minHeap.size() < k || num > minHeap.top())
                minHeap.push(num);

            // Ensure heap size doesn't exceed k
            if ((int)minHeap.size() > k)
                minHeap.pop();
        }

        // The root of the heap is the k-th largest element
        return minHeap.top();
    }
};