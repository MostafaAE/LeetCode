/**
 * Approach:
 * 1. Use a sliding window approach to count all valid subarrays where the difference between 
 *    the maximum and minimum elements in the current window is ≤ 2.
 * 2. Maintain two heaps:
 *    - `maxHeap` to track the maximum value in the current window.
 *    - `minHeap` to track the minimum value in the current window.
 * 3. Expand the window by incrementing `right`, pushing the index into both heaps.
 * 4. If the difference between the maximum and minimum elements in the window exceeds 2:
 *    - Shrink the window by incrementing `left`.
 *    - Remove indices from the heaps that fall outside the window.
 * 5. For every valid window, add `(right - left + 1)` to the result, which is the number of subarrays ending at `right`.
 * 6. Continue until `right` traverses the entire array.
 * 
 * Complexity:
 * Time Complexity: O(n log n)
 * - Each index is pushed into and popped from the heaps at most once, and heap operations are O(log n).
 * Space Complexity: O(n)
 * - Space for the `maxHeap` and `minHeap`.
 */
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        int n = nums.size(), left{}, right{};
        long long result{};
        
        priority_queue<int, vector<int>, function<bool(int, int)>> minHeap(
            [&nums](int a, int b) { return nums[a] > nums[b]; });
        priority_queue<int, vector<int>, function<bool(int, int)>> maxHeap(
            [&nums](int a, int b) { return nums[a] < nums[b]; });
        
        while(right < n)
        {
            // Push the current index into heaps
            minHeap.push(right);
            maxHeap.push(right);
            
            // Shrink the window if the condition is violated
            while(left < right && nums[maxHeap.top()] - nums[minHeap.top()] > 2)
            {
                ++left;
                
                // Remove indices that are now outside the window
                while (!maxHeap.empty() && maxHeap.top() < left) 
                    maxHeap.pop();
                
                while (!minHeap.empty() && minHeap.top() < left) 
                    minHeap.pop();    
            }
            
            // Add the count of valid subarrays ending at `right`
            result += right - left + 1;
            ++right;
        }
        
        return result;
    }
};