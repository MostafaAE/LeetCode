/*
 * Approach:
 * We want to find the length of the longest harmonious subsequence.
 * A harmonious subsequence is one where the difference between the maximum and minimum value is exactly 1.
 *
 * Steps:
 * 1. Count the frequency of each number using an unordered_map.
 * 2. For each number in the map, check if either (num - 1) or (num + 1) exists.
 *    - If so, the potential subsequence length is freq[num] + freq[num ± 1].
 * 3. Keep track of the maximum length encountered.
 *
 * Time Complexity  : O(n), where n is the number of elements in `nums`.
 *                    One pass to build the frequency map, and one pass to check neighboring elements.
 * Space Complexity : O(n), for the unordered_map storing frequencies.
 */

class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        unordered_map<int, int> numFreq;

        // Count frequencies of each number
        for (int num : nums)
            ++numFreq[num];

        int result = 0;

        // Check neighbors for harmonious subsequence
        for (auto& [num, freq] : numFreq)
        {
            if (numFreq.count(num - 1))
                result = max(result, freq + numFreq[num - 1]);

            if (numFreq.count(num + 1))
                result = max(result, freq + numFreq[num + 1]);
        }

        return result;
    }
};