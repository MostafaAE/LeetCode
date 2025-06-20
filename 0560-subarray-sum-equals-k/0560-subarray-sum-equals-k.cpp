/*
 * Approach:
 * - Prefix Sum + Hash Map
 * - Keep track of prefix sums seen so far and their frequencies in a map.
 * - For each element, compute the current prefix sum.
 * - Check if (currentSum - k) exists in the map — if yes, that means there is a subarray that sums to k.
 * - Add the frequency of (currentSum - k) to the count.
 * - Update the map with the current prefix sum.
 *
 * Time Complexity: O(n), where n = size of nums
 * Space Complexity:
 * - O(n), for the hash map to store prefix sums.
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> sumFreq;
        int currentSum = 0, count = 0;    

        sumFreq[0] = 1; // Base case: sum 0 seen once

        for (int num : nums)
        {
            currentSum += num;

            // If (currentSum - k) exists, add its frequency to the result
            count += sumFreq[currentSum - k];

            // Update frequency of currentSum
            ++sumFreq[currentSum];
        }

        return count;
    }
};