/**
 * Approach:
 * - We want both arrays to have the same sum after replacing all zeros with positive integers (≥1).
 * - The best we can do is to replace each zero with 1 to minimize the total increase.
 * - So, we compute:
 *   - The current sum of both arrays.
 *   - The number of zeros in both arrays.
 * - Then, the minimum possible total for each array is: current sum + count of zeros.
 * - If an array has no zeros, its sum is fixed. So, if its fixed sum is less than the other array's minimum achievable total,
 *   it's impossible to equalize the sums, hence return -1.
 * - Otherwise, return the maximum of both (they must equal after adding minimal values to zeros).

 * Time Complexity: O(N + M), where N and M are the lengths of nums1 and nums2.
 * Space Complexity: O(1), only constant space used.
 */

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        long long sum1 = 0, sum2 = 0;
        int zeros1 = 0, zeros2 = 0;

        for (int val : nums1) 
        {
            sum1 += val;
            zeros1 += (val == 0);
        }

        for (int val : nums2) 
        {
            sum2 += val;
            zeros2 += (val == 0);
        }

        // If one array has no zeros but its sum is less than the other's minimum achievable sum
        if ((zeros1 == 0 && sum1 < sum2 + zeros2) ||
            (zeros2 == 0 && sum2 < sum1 + zeros1)) 
        {
            return -1;
        }

        // Both arrays can reach this maximum total
        return max(sum1 + zeros1, sum2 + zeros2);
    }
};