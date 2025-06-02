class Solution {
public:
    /* 
     * Approach:
     * Divide and Conquer (Binary Exponentiation)
     * - If n is negative, we invert x and make n positive.
     * - We recursively compute x^n by dividing the problem into halves:
     *   - x^n = (x^(n/2))^2 if n is even
     *   - x^n = (x^(n/2))^2 * x if n is odd
     *
     * Complexity:
     * Time Complexity  : O(log n) — each call reduces n by half
     * Space Complexity : O(log n) — recursion stack depth
     */
    double myPow(double x, int n)
    {
        // If exponent is negative, invert x and take abs(n)
        if (n < 0)
            x = 1 / x;

        // Convert n to long long to handle edge case when n == INT_MIN
        return pow(x, llabs(n));
    }
    
private:
    // Helper function to recursively compute power using divide and conquer
    double pow(double x, long long n)
    {
        if (n == 0)
            return 1;

        // Recursively compute half power
        double result = pow(x, n / 2);
        result *= result;

        // If n is odd, multiply once more by x
        if (n&1)
            result *= x;

        return result;
    }
};
