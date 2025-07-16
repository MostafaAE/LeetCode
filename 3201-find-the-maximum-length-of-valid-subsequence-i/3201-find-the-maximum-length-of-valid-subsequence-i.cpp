/*
 * Approach:
 * We are trying to find the maximum length of a subsequence in `nums` that satisfies one of the following:
 * 1. All elements are odd.
 * 2. All elements are even.
 * 3. Alternating odd-even pattern.
 * 4. Alternating even-odd pattern.
 *
 * We iterate once through the array and maintain:
 * - `oddCount`: count of all odd numbers.
 * - `evenCount`: count of all even numbers.
 * - `altOddEvenCount`: length of alternating sequence starting with odd.
 * - `altEvenOddCount`: length of alternating sequence starting with even.
 *
 * For alternation, we use flags to track the expected parity at each step.
 *
 * Time Complexity  : O(n), where n is the size of the input array.
 * Space Complexity : O(1), constant space.
 */

class Solution {
public:
    int maximumLength(vector<int>& nums) 
    {
        int oddCount = 0, evenCount = 0;
        int altOddEvenCount = 0, altEvenOddCount = 0;

        // Expectation flags for alternating sequences
        bool expectOddInAltOddEven = true;
        bool expectEvenInAltEvenOdd = true;

        for (int num : nums)
        {
            bool isOdd = num & 1;

            // Count total odd/even numbers
            if (isOdd)
                ++oddCount;
            else
                ++evenCount;

            // Track alternating sequence starting with odd
            if ((isOdd && expectOddInAltOddEven) || (!isOdd && !expectOddInAltOddEven))
            {
                ++altOddEvenCount;
                expectOddInAltOddEven = !expectOddInAltOddEven;
            }

            // Track alternating sequence starting with even
            if ((isOdd && !expectEvenInAltEvenOdd) || (!isOdd && expectEvenInAltEvenOdd))
            {
                ++altEvenOddCount;
                expectEvenInAltEvenOdd = !expectEvenInAltEvenOdd;
            }
        }

        return max({oddCount, evenCount, altOddEvenCount, altEvenOddCount});
    }
};