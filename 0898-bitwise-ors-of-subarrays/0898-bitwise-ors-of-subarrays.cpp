/*
 * Approach:
 * - Use dynamic programming with hash sets to track bitwise OR results.
 * - For each number in the array:
 *   - Start a new hash set `next` to store current OR values.
 *   - Add the number itself to `next` (as a subarray of length 1).
 *   - For each value `val` in the previous set `cur`, compute `val | num`
 *     and insert it into `next` (extends previous subarrays by one element).
 *   - Replace `cur` with `next` for the next iteration.
 *   - Accumulate all values from `cur` into the global result set.
 * 
 * Time Complexity: O(n * 30)
 * - Each number has at most 30 different OR results (due to 32-bit integer constraints),
 *   and we loop through n elements. So it's effectively O(n * 30).
 *
 * Space Complexity: O(n * 30)
 * - Worst-case space usage is similar due to storing distinct OR values.
 */

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int> result;   // Stores all unique OR results
        unordered_set<int> cur;      // Stores OR results ending at previous element

        for (int num : arr) 
        {
            unordered_set<int> next;
            next.insert(num);

            // Extend all previous subarrays with current number
            for (int val : cur)
                next.insert(val | num);

            // Move current set to cur for next iteration
            cur = move(next);  
            result.insert(cur.begin(), cur.end());
        }

        return result.size();
    }
};