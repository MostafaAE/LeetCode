/*
 * Approach:
 * 1. For each a, keep track of the two smallest b's such that (a, b) is a conflicting pair (to determine current and potential next conflict boundaries).
 *    - This helps determine the longest valid subarray starting at `a` and what would change if we remove a conflict.
 * 
 * 2. Traverse from right to left:
 *    - Track the smallest `b` encountered so far (`minB1[bestIndex]`).
 *    - For each index `i`, add the number of valid subarrays starting at `i` that end before the smallest conflicting `b`.
 *    - Also calculate the potential subarrays we could recover if we removed the most limiting conflict (`lostSubarrays[i]`).
 * 
 * 3. After the traversal:
 *    - Find the conflict removal that restores the maximum number of subarrays.
 *    - Return the sum of valid subarrays + maxRestored.
 * 
 * Time Complexity: O(n + m)
 *   - n = array size, m = number of conflicting pairs.
 *
 * Space Complexity: O(n)
 */

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) 
    {
        vector<int> minB1(n + 1, INT_MAX); // smallest 'b' for each 'a'
        vector<int> minB2(n + 1, INT_MAX); // second smallest 'b' for each 'a'

        // Step 1: Track smallest and second smallest conflicting b's for each a
        for (const auto& pair : conflictingPairs) 
        {
            int a = min(pair[0], pair[1]);
            int b = max(pair[0], pair[1]);

            if (b < minB1[a]) 
            {
                minB2[a] = minB1[a];
                minB1[a] = b;
            } 
            else if (b < minB2[a]) 
            {
                minB2[a] = b;
            }
        }

        // Step 2: Greedily count valid subarrays and track potential gains from removing a conflict
        long long totalValid = 0;
        int bestIndex = n;
        int bestSecondB = INT_MAX;

        vector<long long> lostSubarrays(n + 1, 0);

        for (int i = n; i >= 1; i--) 
        {
            // Update bestIndex (holding the smallest b) and bestSecondB (next conflict)
            if (minB1[bestIndex] > minB1[i]) 
            {
                bestSecondB = min(bestSecondB, minB1[bestIndex]);
                bestIndex = i;
            } 
            else 
            {
                bestSecondB = min(bestSecondB, minB1[i]);
            }

            // Count valid subarrays starting at i that end before the earliest conflict
            int validEnd = min(minB1[bestIndex], n + 1);
            totalValid += validEnd - i;

            // Track how many subarrays are "lost" due to conflict — might be restored later
            int secondEnd = min(min(bestSecondB, minB2[bestIndex]), n + 1);
            lostSubarrays[bestIndex] += secondEnd - validEnd;
        }

        // Step 3: Restore max subarrays by removing one conflict
        long long maxRestored = *max_element(lostSubarrays.begin(), lostSubarrays.end());

        return totalValid + maxRestored;
    }
};