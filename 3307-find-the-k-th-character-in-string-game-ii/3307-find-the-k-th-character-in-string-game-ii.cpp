/*
 * Approach:
 * To find the k-th character (1-indexed), we backtrack through the construction:
 * - At each step, we check if `k` lies in the second half of the string.
 * - If so, subtract the size of the first half, and accumulate the transformation shifts.
 * - When k == 1, we reach the original character and apply all collected shifts.
 * 
 * Time Complexity  : O(log k), since we reduce k using powers of 2.
 * Space Complexity : O(1), constant extra space.
 */

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) 
    {
        int shiftCount = 0;

        // Work backwards to trace the original position of the k-th character
        while (k > 1)
        {
            // Find the largest power of 2 less than k
            int exp = log2(k - 1);
            long long size = 1LL << exp;

            // Move k to its mirrored position in the first half
            k -= size;

            // Accumulate transformation shifts
            shiftCount += operations[exp];
        }

        // Apply total shifts to the initial character 'a'
        return 'a' + (shiftCount % 26);
    }
};