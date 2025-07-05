/*
 * Approach:
 * We are looking for the largest integer in the array such that its frequency is equal to its value.
 * 
 * - Use an unordered_map to count the frequency of each number in the array.
 * - Iterate through the map and check for each number if it equals its frequency.
 * - Keep track of the maximum such number (lucky number) found.
 *
 * Time Complexity  : O(n), where n is the size of the input array.
 * Space Complexity : O(n), for storing frequencies in the unordered_map.
 */

class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int, int> numToFreq;
        int result = -1;

        // Count the frequency of each number
        for (int num : arr)
        {
            ++numToFreq[num];
        }

        // Check for lucky numbers
        for (auto [num, freq] : numToFreq)
        {
            if (num == freq)
                result = max(result, num);
        }

        return result;
    }
};