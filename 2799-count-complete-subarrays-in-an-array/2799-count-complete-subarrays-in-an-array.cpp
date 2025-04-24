/**
 * Approach:
 * 1. A "complete subarray" is defined as a subarray that contains **all the distinct elements** of the original array.
 * 2. First, we determine the total number of distinct elements in the input array using a hash set.
 * 3. Then, we use a sliding window approach:
 *    - We expand the `right` pointer and track the frequency of each element in a hash map.
 *    - Whenever the number of distinct elements in the window equals the total distinct elements of the array,
 *      we know every subarray starting at `left` and ending anywhere from `right` to `n-1` is valid.
 *    - So, we add `n - right` to the result and try to shrink the window by moving `left` forward.
 * 
 * Time Complexity: O(n)
 * - Both pointers (`left` and `right`) traverse the array once.
 * - Insertions and deletions in the hash map are O(1) on average.
 * 
 * Space Complexity: O(n)
 * - For storing the count of elements in the current window and distinct elements in a set.
 */
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) 
    {
        unordered_set<int> hashSet(nums.begin(), nums.end()); // To get the total number of distinct elements
        unordered_map<int, int> numToCount; // Frequency map for sliding window

        int distinctCount = hashSet.size();
        int n = nums.size(), result = 0;

        // Sliding window: [left, right]
        for (int right = 0, left = 0; right < n; ++right)
        {
            ++numToCount[nums[right]];

            // Try to contract the window from the left while it remains complete
            while (left <= right && numToCount.size() == distinctCount)
            {
                result += n - right; // All subarrays [left, right], [left, right+1], ..., [left, n-1] are complete
                --numToCount[nums[left]];

                // Remove the element from the map if its count becomes 0
                if (numToCount[nums[left]] == 0)
                    numToCount.erase(nums[left]);

                ++left;
            }
        }

        return result;
    }
};
