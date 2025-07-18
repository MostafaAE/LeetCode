/*
 * Approach:
 * The problem is to partition the array `nums` of size 3n into three equal parts:
 * - First n elements (can be rearranged) → to be minimized
 * - Last n elements (can be rearranged) → to be maximized
 * We want to **minimize the difference** between the sum of the first part and the sum of the third part,
 * given we can choose any n elements for each part.
 *
 * Steps:
 * 1. For the **first 2n elements**, we use a **max-heap** to always keep the n smallest elements seen so far
 *    and store the prefix sums in `part1[i]`.
 * 2. For the **last 2n elements (from back)**, we use a **min-heap** to keep the n largest elements and calculate
 *    the suffix sums while updating the minimum difference between prefix and suffix.
 *
 * Time Complexity  : O(n log n), where n = nums.size() / 3. Each heap operation is log n, and we do 2n operations.
 * Space Complexity : O(n), for storing prefix sums and heaps.
 */

using ll = long long;

class Solution {
public:
    ll minimumDifference(vector<int>& nums) 
    {
        int n = nums.size() / 3;

        // Max-heap to keep track of n smallest elements from the first 2n elements
        priority_queue<int> maxHeap;
        ll minSumSoFar = 0;

        // Initialize sum with the first n elements
        for (int i = 0; i < n; ++i)
        {
            minSumSoFar += nums[i];
            maxHeap.push(nums[i]);
        }

        // part1[i] holds the minimum sum of n elements from the first i+n elements
        vector<ll> part1(n + 1);
        part1[0] = minSumSoFar;

        // For each i from n to 2n-1, update the heap with nums[i]
        for (int i = n; i < 2 * n; ++i)
        {
            minSumSoFar += nums[i];
            maxHeap.push(nums[i]);

            // Remove the largest to keep only the n smallest
            minSumSoFar -= maxHeap.top();
            maxHeap.pop();

            // Store the new sum in part1
            part1[i - n + 1] = minSumSoFar;
        }

        // Min-heap to keep track of n largest elements from the last 2n elements (processed in reverse)
        priority_queue<int, vector<int>, greater<>> minHeap;
        ll maxSumSoFar = 0;

        // Initialize the maxSum with the last n elements
        for (int i = 2 * n; i < 3 * n; ++i)
        {
            maxSumSoFar += nums[i];
            minHeap.push(nums[i]);
        }

        // Initial result using prefix from part1[n] and suffix from last n
        ll result = part1[n] - maxSumSoFar;

        // Move backward from index 2n - 1 to n
        for (int i = 2 * n - 1; i >= n; --i)
        {
            maxSumSoFar += nums[i];
            minHeap.push(nums[i]);

            // Remove the smallest to keep only the n largest
            maxSumSoFar -= minHeap.top();
            minHeap.pop();

            // Update the result with the minimum difference
            result = min(result, part1[i - n] - maxSumSoFar);
        }

        return result;
    }
};