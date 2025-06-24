/*
 * Approach:
 * Two-Pointer Technique
 * - First, collect all indices where nums[i] == key into keyIndices.
 * - Then, for each index `i` in nums:
 *     - Move pointer `j` in keyIndices forward while the current keyIndex is too far to the left.
 *     - If the current keyIndex[j] is within distance k of index i, add i to the result.
 * 
 * Time Complexity : O(n), where n is the size of nums.
 * Space Complexity: O(m), where m is the number of occurrences of key (stored in keyIndices).
 */

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        int n = nums.size();
        vector<int> keyIndices, result;

        // First pass: collect key indices
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == key)
                keyIndices.push_back(i);
        }

        // Second pass: two-pointer to find k-distant indices
        for (int i = 0, j = 0; i < n; ++i)
        {
            while (j < keyIndices.size() && i - keyIndices[j] > k)
            {
                ++j;
            }

            if (j < keyIndices.size() && abs(keyIndices[j] - i) <= k)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};