class Solution {
public:
    /**
     * Approach:
     * - Start from the largest power of 3 (3^16).
     * - Try to build `n` by using each power at most once.
     * - If any division results in a quotient > 1, return `false` (it means `n` needs more than one of that power).
     * - Continue reducing `n` using modulus.
     * - If `n` becomes zero, it means we successfully represented `n` using distinct powers of 3.
     * 
     * Complexity:
     * - **Time Complexity:** O(log n) → We divide `n` at most log_3(n) times.
     * - **Space Complexity:** O(1) → Constant extra space.
     */
    bool checkPowersOfThree(int n) 
    {
        for (int powerOfThree = 1; powerOfThree <= n; powerOfThree *= 3)
        {
            if ((n % (powerOfThree * 3)) / powerOfThree > 1) 
                return false;
        }
        return true;
    }
};
