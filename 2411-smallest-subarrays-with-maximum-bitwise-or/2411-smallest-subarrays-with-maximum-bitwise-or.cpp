/*
 * Approach:
 * - Use a `pos[31]` array to track the last index where each bit (0 to 30) was seen.
 * - Iterate from right to left:
 *    - For each bit not present in nums[i], check where the next such bit appears 
 *      using `pos` and extend the subarray to that position.
 *    - For each bit present in nums[i], update its last seen position in `pos`.
 * - The maximum right extension index `j` gives the minimum subarray length as `j - i + 1`.
 * 
 * Time Complexity: O(n * 31) = O(n)
 * - We loop through each element and each of the 31 bit positions.
 * 
 * Space Complexity: O(31) = O(1)
 */

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int> pos(31, -1); // Stores latest index of each bit
        vector<int> result(n);

        for (int i = n - 1; i >= 0; --i) 
        {
            int j = i;

            for (int bit = 0; bit < 31; ++bit) 
            {
                // If nums[i] does NOT have this bit set
                if (!(nums[i] & (1 << bit))) 
                {
                    // But it was seen in a later number
                    if (pos[bit] != -1)
                        j = max(j, pos[bit]); // Extend to include that number
                } 
                else 
                {
                    // If nums[i] has this bit set, update its last seen position
                    pos[bit] = i;
                }
            }

            // Minimum subarray length starting at i with full OR value
            result[i] = j - i + 1;
        }

        return result;
    }
};