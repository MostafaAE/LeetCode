/*
 * Approach:
 * We're building the longest subsequence from the binary string `s` such that its decimal value ≤ `k`.
 * Since leading zeros are allowed in subsequences, we first count all '0's—they don't contribute to the value.
 * Then we greedily try to include '1's from the end (least significant bit) to the beginning,
 * tracking the resulting binary number. If including a '1' keeps the value ≤ `k`, we include it.
 * 
 * The current implementation is a bit trickier: it simulates forming the binary value left-to-right,
 * tracking positions of the '1' bits and removing the most significant bit if the value exceeds `k`.

 * Time Complexity  : O(n), where n = s.length().
 * Space Complexity : O(n), due to the queue for storing bit positions.
 */

class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int n = (int)s.size(), val = 0, count = 0;
        queue<int> bitPositions;

        for(int i = 0 ; i < n ; ++i)
        {
            val <<= 1;

            if(s[i] == '1')
            {
                val |= 1;
                bitPositions.push(i);
            }

            if(val > k)
            {
                int bitPositionToRemove = bitPositions.front();
                bitPositions.pop();
                val &= ~(1 << (i - bitPositionToRemove));  // Remove the oldest bit from val
            }
            else
            {
                ++count;
            }
        }

        return count;
    }
};