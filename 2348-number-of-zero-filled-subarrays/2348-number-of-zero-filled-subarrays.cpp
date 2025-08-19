class Solution 
{
public:
    /*
    * Approach:
    * - We need to count the number of subarrays consisting entirely of zeros.
    * - Key insight:
    *     - If we encounter consecutive zeros, they form multiple subarrays.
    *     - Example: [0, 0, 0]
    *         - Subarrays: [0], [0], [0,0], [0,0], [0,0,0]
    *         - Count = 1 + 2 + 3 = 6
    *     - So if there are k consecutive zeros, the contribution is k.
    * - Implementation:
    *     - Traverse the array while maintaining a counter of consecutive zeros.
    *     - For each zero, increment the counter; for non-zero, reset it.
    *     - Add the counter to the result at each step.
    *
    * Time Complexity: O(n)
    * Space Complexity: O(1)
    */
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        long long result = 0;
        int count = 0;

        for (int num : nums)
        {
            if (num == 0)
                ++count;       // Extend consecutive zero streak
            else
                count = 0;     // Reset streak when a non-zero is found

            // Add current streak length to result
            result += count;
        }

        return result;
    }
};