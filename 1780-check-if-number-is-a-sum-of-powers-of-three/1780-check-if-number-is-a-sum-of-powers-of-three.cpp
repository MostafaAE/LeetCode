class Solution {
public:
    /**
     * Approach:
     * - We start with the largest power of 3 within a reasonable range (`3^16`).
     * - Iterate while `n > 0`:
     *   - Check if `n` contains any coefficient greater than `1` when divided by the current power of 3.
     *   - If it does (`n / powerOfThree > 1`), return false (as it means we need more than one of a power).
     *   - Otherwise, subtract the contribution of this power from `n` (`n %= powerOfThree`).
     *   - Move to the next lower power (`powerOfThree /= 3`).
     * - If `n` is reduced to `0`, it means we successfully represented it using distinct powers of 3.
     * 
     * Complexity Analysis:
     * - Time Complexity: O(log₃(n)) 
     * - Space Complexity: O(1)
     */
    bool checkPowersOfThree(int n) 
    {
        int powerOfThree = pow(3, 16);

        while (n > 0) 
        {
            if (n / powerOfThree > 1)
                return false; // If we need more than one of this power, it's not possible
            
            n %= powerOfThree;
            powerOfThree /= 3;
        }

        return n == 0;
    }
};
